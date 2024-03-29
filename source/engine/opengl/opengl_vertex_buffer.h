#pragma once
#include "engine/rendering/buffer_layout.h"
#include "engine/rendering/vertex_buffer.h"
#include <cstdint>

namespace atom::engine
{
    class opengl_vertex_buffer: public vertex_buffer
    {
    public:
        opengl_vertex_buffer(float* vertices, u32 count);
        virtual ~opengl_vertex_buffer();

    public:
        virtual auto bind() const -> void override;
        virtual auto unbind() const -> void override;
        virtual auto get_count() const -> u32 override;
        virtual auto set_layout(const buffer_layout& layout) -> void override;
        virtual auto get_layout() -> buffer_layout& override;

    private:
        uint32_t _renderer_id;
        u32 _count;
        buffer_layout _layout;
    };
}
