import jinja2

component_template = """
#pragma once
#include "ecs/ecs.h"

#define {{name.upper()}}_PROPERTIES \\
    {% for prop in properties %}
    PROP({{prop.name}}, {{prop.type}}){{ " \\" if not loop.last else "" }}
    {% endfor %}

struct {{name}}Component : public Component {
    {% for prop in properties %}
    {{prop.type}} {{prop.name}};
    {% endfor %}
    
    void inspect() {
        {% for prop in properties %}
        ImGui::Drag{{"Float" if prop.type == "float" else "Int"}}(
            "{{prop.name}}", &{{prop.name}});
        {% endfor %}
    }
};
"""

def generate_component(name, properties):
    return jinja2.Template(component_template).render(
        name=name,
        properties=properties
    )