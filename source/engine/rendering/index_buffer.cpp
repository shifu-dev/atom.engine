#include "index_buffer.h"
#include "engine/opengl/opengl_index_buffer.h"
#include "engine/rendering/renderer.h"

namespace atom::engine
{
    auto index_buffer::create(uint32_t* indices, u32 count) -> index_buffer*
    {
        switch (renderer_api::get_api())
        {
            case renderer_api::api::opengl: return new opengl_index_buffer(indices, count);
            case renderer_api::api::none:   ATOM_PANIC("renderer_api::api::none is not supported."); break;
            default:                   ATOM_PANIC("invalid renderer_api type."); break;
        }

        return nullptr;
    }
}
