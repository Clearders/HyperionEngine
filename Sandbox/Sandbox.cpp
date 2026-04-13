#include "imgui_internal.h"
#include "../Hyperion/src/Hyperion.h"
#include "examples/libs/glfw/include/GLFW/glfw3.h"
#include <glm/gtc/matrix_transform.hpp>

#include "glm/gtc/type_ptr.hpp"

class ExampleLayer : public Hyperion::Layer
{
public:
    ExampleLayer()
        : Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f, 0.0f, 0.0f), m_CameraMoveSpeed(1.0f), m_SquarePosition(0.0f)
    {
        m_VertexArray.reset(Hyperion::VertexArray::Create());

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.1f, 0.8f, 0.2f, 0.8f, 1.0f,
            0.5f, -0.5f, 0.1f, 0.2f, 0.3f, 0.8f, 1.0f,
            0.0f, 0.5f, 0.1f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        Hyperion::Ref<Hyperion::VertexBuffer> vertexBuffer;
        vertexBuffer.reset(Hyperion::VertexBuffer::Create(vertices, sizeof(vertices)));

        Hyperion::BufferLayout layout = {
            {Hyperion::ShaderDataType::Float3, "a_Position"},
            {Hyperion::ShaderDataType::Float4, "a_Color"}
        };

        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        uint32_t indices[3] = {0, 1, 2};
        Hyperion::Ref<Hyperion::IndexBuffer> indexBuffer;
        indexBuffer.reset(Hyperion::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVertexArray.reset(Hyperion::VertexArray::Create());

        float squareVertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
        };

        Hyperion::Ref<Hyperion::VertexBuffer> squareVertexBuffer;
        squareVertexBuffer.reset(Hyperion::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

        Hyperion::BufferLayout squareVertexBufferLayout = {
            {Hyperion::ShaderDataType::Float3, "a_Position"},
            {Hyperion::ShaderDataType::Float2, "a_TexCoord"},
        };
        squareVertexBuffer->SetLayout(squareVertexBufferLayout);
        m_SquareVertexArray->AddVertexBuffer(squareVertexBuffer);

        uint32_t squareIndices[6] = {0, 1, 2, 2, 3, 0};
        Hyperion::Ref<Hyperion::IndexBuffer> squareIndexBuffer;
        squareIndexBuffer.reset(Hyperion::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
        m_SquareVertexArray->SetIndexBuffer(squareIndexBuffer);

        std::string vertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec4 a_Color;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec3 v_Position;
            out vec4 v_Color;


            void main()
            {
                v_Position = a_Position;
                v_Color = a_Color;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;

            in vec3 v_Position;
            in vec4 v_Color;

            void main()
            {
                color = v_Color;
            }
        )";

        m_Shader.reset(Hyperion::Shader::Create(vertexSrc, fragmentSrc));

        std::string flatColorShaderVertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;


            out vec3 v_Position;

            void main()
            {
                v_Position = a_Position;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";

        std::string flatColorShaderFragmentSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;

            in vec3 v_Position;

            uniform vec4 u_Color;

            void main()
            {
                color = u_Color;
            }
        )";

        m_FlatColorShader.reset(Hyperion::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));

        std::string textureShaderVertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec2 a_TexCoord;

            uniform mat4 u_ViewProjection;
            uniform mat4 u_Transform;

            out vec2 v_TexCoord;

            void main()
            {
                v_TexCoord = a_TexCoord;
                gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
            }
        )";

        std::string textureShaderFragmentSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;

            in vec2 v_TexCoord;

            uniform sampler2D u_Texture;

            void main()
            {
                color = texture(u_Texture, v_TexCoord);
            }
        )";

        m_TextureShader.reset(Hyperion::Shader::Create(textureShaderVertexSrc, textureShaderFragmentSrc));

        m_Texture = Hyperion::Texture2D::Create("assets/textures/test.png");

        auto glTextureShader = std::dynamic_pointer_cast<Hyperion::OpenGLShader>(m_TextureShader);
        if (glTextureShader)
        {
            glTextureShader->Bind();
            glTextureShader->UploadUniformInt("u_Texture", 0);
        }
    }

    void OnUpdate(Hyperion::Timestep ts) override
    {

        //HYPERION_INFO("ExampleLayer::Update");

        // if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_TAB))
        // {
        //     HYPERION_TRACE("Tab key is pressed!");
        // }

        float time = ts;

        if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_A))
        {
            m_CameraPosition.x -= m_CameraMoveSpeed * ts;
        }else if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_D))
        {
            m_CameraPosition.x += m_CameraMoveSpeed * ts;
        }

        if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_S))
        {
            m_CameraPosition.y -= m_CameraMoveSpeed * ts;
        }else if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_W))
        {
            m_CameraPosition.y += m_CameraMoveSpeed * ts;
        }

        if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_E))
        {
            m_CameraRotation -= m_CameraRotationSpeed * ts;
        }else if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_Q))
        {
            m_CameraRotation += m_CameraRotationSpeed * ts;
        }

        Hyperion::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
        Hyperion::RenderCommand::Clear();

        m_Camera.SetPosition(m_CameraPosition);
        m_Camera.SetRotation(m_CameraRotation);

        Hyperion::Renderer::BeginScene(m_Camera);

        //glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_SquarePosition);
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

        // glm::vec4 redColor = glm::vec4(0.8f, 0.2f, 0.3f, 1.0f);
        // glm::vec4 greenColor = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
        // glm::vec4 blueColor = glm::vec4(0.2f, 0.3f, 0.8f, 1.0f);

        //Hyperion::MaterialRef material = new Hyperion::Material::Create(m_FlatColorShader);

        //material->SetFloat4("u_Color", redColor);
        //squareMesh->SetMaterial(material);

        // Guard shader type before dereferencing the OpenGL-specific functions.
        auto glFlatColorShader = std::dynamic_pointer_cast<Hyperion::OpenGLShader>(m_FlatColorShader);
        if (!glFlatColorShader)
        {
            HYPERION_ERROR("Flat color shader cast failed. Renderer API: {}", static_cast<int>(Hyperion::Renderer::GetAPI()));
            return;
        }

        glFlatColorShader->Bind();
        glFlatColorShader->UploadUniformFloat4("u_Color", glm::vec4(m_SquareColor, 1.0f));


        for (int y = 0; y < 20; y++)
        {
            for (int x = 0; x < 20; x++)
            {
                glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
                glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                Hyperion::Renderer::Submit(m_FlatColorShader, m_SquareVertexArray, transform);
            }
        }

        m_Texture->Bind();
        Hyperion::Renderer::Submit(m_TextureShader,m_SquareVertexArray, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


        //Tringle
        //Hyperion::Renderer::Submit(m_Shader, m_VertexArray);


        Hyperion::Renderer::EndScene();

    }

    virtual void OnImGuiRender() override
    {
        ImGui::Begin("Settings##SandboxLayer");
        ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
        ImGui::End();
    }

    void OnEvent(Hyperion::Event& event) override
    {
        // if (Hyperion::Input::IsKeyPressed(HYPERION_KEY_TAB))
        // {
        //     HYPERION_TRACE("Tab key is pressed!");
        // }
    }

private:
    Hyperion::Ref<Hyperion::VertexArray> m_VertexArray;
    Hyperion::Ref<Hyperion::Shader> m_Shader;

    Hyperion::Ref<Hyperion::VertexArray> m_SquareVertexArray;
    Hyperion::Ref<Hyperion::Shader> m_FlatColorShader, m_TextureShader;

    Hyperion::Ref<Hyperion::Texture2D> m_Texture;

    Hyperion::OrthographicCamera m_Camera;
    glm::vec3 m_CameraPosition;
    float m_CameraRotation = 0.0f;

    float m_CameraRotationSpeed = 40.0f;
    float m_CameraMoveSpeed = 0.1f;

    glm::vec3 m_SquarePosition;
    float m_SquareMoveSpeed = 1.0f;

    glm::vec3 m_SquareColor = {0.2f, 0.3f, 0.8f};
};


class Sandbox : public Hyperion::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer);;
    }

    ~Sandbox() override
    {
    }
};

Hyperion::Application* CreateApplication()
{
    return new Sandbox();
}
