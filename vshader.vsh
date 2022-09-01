attribute highp vec4 a_position;
attribute highp vec3 a_normal;
attribute highp vec2 a_textcoord;

uniform highp mat4 u_projection_matrix;
uniform highp mat4 u_model_matrix;
uniform highp mat4 u_view_matrix;

varying highp vec2 v_textcoord;
varying highp vec3 v_normal;
varying highp vec4 v_position;

void main(void)
{
    mat4 mv_matrix = u_model_matrix * u_view_matrix;

    gl_Position = u_projection_matrix * mv_matrix * a_position;

    v_textcoord = a_textcoord;
    v_normal = normalize(vec3(mv_matrix * vec4(a_normal, 0.0)));
    v_position = mv_matrix * a_position;
}
