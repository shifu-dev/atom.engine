#include "atom/engine/rendering/scene.h"
#include "engine/rendering/renderer_2d.h"

namespace atom::engine
{
    scene::scene()
    {
        _entity_manager = new entity_manager();
    }

    scene::~scene()
    {
        delete _entity_manager;
    }

    auto scene::on_update(time_step time) -> void
    {
        class camera* camera = nullptr;
        const mat4* camera_transform = nullptr;

        auto group = _entity_manager->get_internal()->view<transform_component, camera_component>();
        for (auto entity : group)
        {
            auto [transform, camera_comp] =
                group.get<transform_component, camera_component>(entity);

            camera = &camera_comp.get_camera();
            camera_transform = &transform.get_matrix();
            break;
        }

        if (camera != nullptr)
        {
            renderer_2d::begin_scene(camera, *camera_transform);

            entt::registry* entt_registry = _entity_manager->get_internal();
            auto group = entt_registry->group<transform_component>(entt::get<sprite_component>);
            for (auto entity : group)
            {
                const auto& [transform, sprite] =
                    group.get<transform_component, sprite_component>(entity);
                renderer_2d::draw_quad(transform.get_matrix(), sprite.get_color());
            }

            renderer_2d::end_scene();
        }
    }
}
