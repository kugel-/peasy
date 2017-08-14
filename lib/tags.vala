using GLib;
using Geany;

namespace Peasy
{

public class TagQuery : GLib.Object
{
    public enum Source {
        GLOBAL_TAGS,
        SESSION_TAGS,
    }

    private int data_sources;
    private List<StringBuilder> names;

    public TagQuery.with_source(Source source)
    {
        this.data_sources = source;
    }

    public int match_name(string name, int len)
    {
        var gstr = new StringBuilder();
        gstr.append_len(name, len);
        names.append((owned) gstr);
        return 0;
    }

#if 0
    public int unique()
    {
        make_unique = true;
        return 0;
    }
#endif

    private static int compare_fn(void *_key, void *_tag)
    {
        StringBuilder *key = (StringBuilder *) _key;
        TMTag *tag = *(TMTag **) _tag;

        return Posix.strncmp(key->str, tag->name, key->len);
    }

    private GenericArray<unowned TMTag> get_tags_by_name()
    {
        GenericArray<unowned TMTag> ret = new GenericArray<unowned TMTag>();
        unowned StringBuilder key;
        GenericArray tags = peasy_plugin.geany_data.app.tm_workspace.tags_array;
        TMTag **match;
        TMTag **first;
        TMTag **last;
        TMTag *tag;

        key = names.nth_data(0);
        match = (TMTag **) Posix.bsearch(key , tags.data, tags.length,
                                         sizeof(Geany.TMTag *), compare_fn);

        if (match == null)
            return ret;

        /* bsearch finds any of the matching tags, if there are more than
         * one. We need to locate the first and last one manually. */
        first = match;
        while (*first != tags.data[0])
        {
            tag = *(first-1);
            if (Posix.strncmp(key.str, tag->name, key.len) != 0)
                break;

            first--;
        }

        last = match;
        while (*last != tags.data[tags.length-1])
        {
            tag = *last;
            if (Posix.strncmp(key.str, tag->name, key.len) != 0)
                break;

            last++;
        }

        for (tag = *first++; tag != *last; tag = *first++)
        {
            ret.add(tag);
#if 0
            if (make_unique)
            {
                TMTag *next = *first;
                while (make_unique && next != *last && tag->name == next->name)
                {
                    next = *first++;
                }
            }
#endif
        }
        return ret;
    }

    private GenericArray<unowned TMTag> get_all_tags()
    {
        var all_tags = peasy_plugin.geany_data.app.tm_workspace.tags_array;
        var ret = new GenericArray<unowned TMTag>(all_tags.length);

        Posix.memcpy(ret.data, all_tags.data, all_tags.length * sizeof(TMTag *));
        return ret;
    }

    public GenericArray<unowned TMTag> exec()
    {
        if (names == null)
            return get_all_tags();
        else
            return get_tags_by_name();
    }
}

}
