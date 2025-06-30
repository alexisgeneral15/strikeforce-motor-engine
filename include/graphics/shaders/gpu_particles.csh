// Particle Vertex Shader
#version 450 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 uv;
layout(location = 3) in float lifetime;

out vec4 v_color;
out vec2 v_uv;
out float v_lifetime;

uniform mat4 u_view_projection;

void main() {
    v_color = color;
    v_uv = uv;
    v_lifetime = lifetime;
    gl_Position = u_view_projection * position;
}

// Particle Fragment Shader
#version 450 core
in vec4 v_color;
in vec2 v_uv;
in float v_lifetime;

out vec4 frag_color;

uniform sampler2D u_texture;

void main() {
    vec4 tex_color = texture(u_texture, v_uv);
    frag_color = v_color * tex_color;
    frag_color.a *= smoothstep(0.0, 0.2, v_lifetime) * 
                   (1.0 - smoothstep(0.8, 1.0, v_lifetime));
}