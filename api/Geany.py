from ..importer import modules

Geany = modules['Geany']._introspection_module

Geany.Editor.indent_type = property(lambda self: self.get_indent_prefs().type,
                                    lambda self, v: self.set_indent_type(v))
Geany.Editor.indent_width = property(lambda self: self.get_indent_prefs().width,
                                     lambda self, v: self.set_indent_width(v))

Geany.Document.__encoding = Geany.Document.encoding
Geany.Document.encoding = property(lambda self: self.__encoding,
                                   lambda self, v: self.set_encoding(v))
Geany.Document.__changed = Geany.Document.changed
Geany.Document.changed = property(lambda self: self.__changed,
                                  lambda self, v: self.set_encoding(v))

Geany.Document.display_name = lambda self: self.get_basename_for_display(-1)
