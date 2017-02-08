
local lgi = require 'lgi'

local GObject = lgi.GObject
local Geany = lgi.Geany
local Peasy = lgi.Peasy

local LuaPlugin = Peasy.Plugin:derive('LuaPlugin', {})

function LuaPlugin:do_enable()
    print("Hello from Lua!!")
    local doc = Geany.Document.new_file("foo")
    self.geany_plugin.geany_data.object.on_document_close = function(obj, doc)
        print(doc.file_name .. " closed (lua)")
        self.priv.doc = nil
    end

    self.priv.doc = doc

    return true
end

function LuaPlugin:do_disable()
    print("Bye from Lua :-(")
    if (self.priv.doc) then
        self.priv.doc.close()
    end
end

return { LuaPlugin }
