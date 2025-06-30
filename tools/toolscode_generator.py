import jinja2

def generate_component(component_name, fields):
    template = """
#pragma once
#include "ecs/ecs.h"

COMPONENT({{name}}) {
    {% for field in fields %}
    {{field.type}} {{field.name}}{% if field.value %} = {{field.value}}{% endif %};
    {% endfor %}
};

LUA_BIND({{name}}) {
    {% for field in fields %}
    .property("{{field.name}}", &{{name}}::{{field.name}}),
    {% endfor %}
});
    """
    
    env = jinja2.Environment()
    return env.from_string(template).render(name=component_name, fields=fields)