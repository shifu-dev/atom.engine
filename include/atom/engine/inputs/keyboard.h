#pragma once
#include "atom.core.h"
#include "atom/engine/inputs/input_device.h"
#include "atom/engine/inputs/keyboard_keys.h"
#include "atom/engine/inputs/keyboard_events.h"

namespace atom::engine
{
    class keyboard: public input_device
    {
    public:
        keyboard(input_device_id id, string name)
            : input_device(id, move(name))
            , _key_states()
        {}

        virtual ~keyboard() {}

    public:
        auto get_key_state(keyboard_key_code key) const -> keyboard_key_state
        {
            return _key_states[(usize::unwrapped_type)key];
        }

        auto is_key_up(keyboard_key_code key) const -> bool
        {
            return get_key_state(key) == keyboard_key_state::up;
        }

        auto is_key_pressed(keyboard_key_code key) const -> bool
        {
            return get_key_state(key) == keyboard_key_state::pressed;
        }

        auto is_key_down(keyboard_key_code key) const -> bool
        {
            return get_key_state(key) == keyboard_key_state::down;
        }

        auto is_key_released(keyboard_key_code key) const -> bool
        {
            return get_key_state(key) == keyboard_key_state::released;
        }

        virtual auto subscribe_event(keyboard_event_listener* listener) -> void = 0;

        virtual auto unsubscribe_event(keyboard_event_listener* listener) -> void = 0;

    protected:
        keyboard_key_state _key_states[(usize::unwrapped_type)keyboard_key_code::MAX + 1];
    };
}