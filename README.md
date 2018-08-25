# Peasy

Write Geany plugins in Python and Lua!

This makes use of libpeas, hence the name.

Overview
--------

This plugin provides the ability two develop Geany plugins in languages
supported by libpeas which includes Python and Lua at the moment. Ruby is
support is under construction.

Libpeas is used to load the actual plugins. Therefore, you are actually writing
extensions. Peasy provides an entry point to make these libpeas extensions
visible as Geany plugins.

In Geany, you have to enable Peasy first. It acts as a proxy plugin. After
activating, Geany will see the aditional plugins enabled by Peasy, which you
can then activate individually.

Peasy also provides some convinience APIs where Geany's own plugin API is
lacking or awkward to use from a non-C language. These APIs are rare, though,
it is preferred to use Geany's API directly.

Geany's API is exposed through gobject-introspection. Peasy ships GI bindings
for Geany and overrides for Python, as well as VAPI files for Vala. Refer to
Geany's official API documentation.

By using gobject-introspection, the APIs exposed are always up-to-date.
Generally, there is no manual intervention required to expose newly-added Geany
APIs.

Included Plugins
----------------

Peasy includes a few plugins that are useful to the author. They also act
as a reference if you have trouble writing your own plugins. However, all
but the bare test plugins are written in Python.


Writing a plugin
----------------

### Create a [myplugin].plugin file

Libpeas uses a .plugin manifest file to learnabout plugins even before loading
them. It's a .ini-style file that mentions the name, author, copyright information
and other stuff. One key element is also which loader to use, which also
determines the file extensions. Another key element is `X-Peasy-API` which is
specific to Peasy and indicates which Geany API version is targetted. This
key is mandatory, although the dynamic nature of the languages enable supporting
ancient Geany versions by proving APIs at runtime.

Example:

```
[Plugin]
Module=myplugin
Loader=python3
Name=My Plugin
Authors=John Doe <johndoe@foo.com>
X-Peasy-API=228
```

### Create a [myplugin].[ext] file

The actual source code file carries the same basename as the .plugin file,
plus the extenion required by the loader. Extensions are .py for Pyton and .lua
for Lua. You can also write native plugins in C. These must compile to a
shared library/DLL, named myplugin.dll on Windows and lib<plugin>.so on
any other system.

### Write a GObject-based class, derived from PeasyPlugin.

The basic entry point is always a GObject-based class, that implements
the PeasyPluginIface interface. The PeasyPluginIface is automatically pulled
in by deriving the type from PeasyPlugin instead of GObject, which is the
recommended method.

The class must provide to methods: "bool enable()" and "void disable()".
Of course, the details are language specific.

```python

class MyPlugin(Peasy.Plugin):
    def do_enable(self):
        return True

    def do_disable(self):
        pass
```

```lua

local MyPlugin = Peasy.Plugin:derive('MyPlugin', {})

function LuaPlugin:do_enable()
    return true
end

function LuaPlugin:do_disable()
end
```

### Extras

Above was basic. You can enhance the plugin by supporting configration and
help. This is done by implementing the PeasyConfigure and PeasyHelp interfaces
respectively. In both cases, it'll look like an ordinary plugin to the user,
because it's configured the same way via the combined plugin configuration
dialog, and the help is visible directly in the plugin manager.

You can also enhance your plugin with UIs created with glade. Simply
ship the glade file and use GtkBuilder to load it at runtime.

For keybindings, Peasy provdes a wrapper API that is easier to use. Have a look
at the PeasyKeyBinding and PeasyKeyGroup classes.

Installation
------------

Peasy uses autoconf and kmake, therefore INSTALL gives a generic overview.

For kmake, see https://github.com/kugel-/kmake.

If you are running from git, then configure does not exist. Run ./autogen.sh to
generate it. In contrast to building Geany, autogen.sh does not automatically
run configure.

Peasy has some dependencies, some of them are compile-time only:

* Geany 1.25 or newer
* Glib
* Libpeas
* Vala toolchain (valac and vapigen)
* Python 3.x, Lua 5.1

Peasy is partly written in Vala, therefore valac is required. Vapigen is
used to create VAPIs for Geany. These are used for Peasy itself, but are
also provided to Vala plugins.

Python and Lua are not required for building Peasy, but obviously Python
plugins need an interpreter. Note that at the moment only Python 3.x and Lua
5.1 are supported (Libpeas upstream lacks support for newer Lua versions).

Further Information
-------------------

See COPYING for license information and INSTALL for installation help. See
AUTHORS for contact information.

