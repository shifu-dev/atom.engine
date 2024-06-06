export module atom.engine:filesystem;

import atom.core;

namespace atom::engine::filesystem
{
    export auto read_file(string_view path) -> result<string, error>
    {
        std::ifstream in(path.get_data(), std::ios::in | std::ios::binary);
        in.seekg(0, std::ios::end);
        size_t count = in.tellg();
        in.seekg( 0 );

        string content = string::with_capacity(count);
        in.read(content.get_mut_data(), count);

        // @todo: fix this, we need to call `string::with_count()` instead.
        return string(ranges::from(content.get_data(), content.get_capacity()));
    }
}
