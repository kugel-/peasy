/*
 * Automatically generated file - do not edit
 */

#include "gtkcompat.h"
#include "Scintilla.h"
#include "ScintillaWidget.h"


/**
 * GeanyBuildGroup: 
 * @GEANY_GBG_FT:  filetype items
 * @GEANY_GBG_NON_FT:  non filetype items.
 * @GEANY_GBG_EXEC:  execute items
 * @GEANY_GBG_COUNT:  count of groups.
 *
 * 
 * Groups of Build menu items. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_GBG_FT,
	GEANY_GBG_NON_FT,
	GEANY_GBG_EXEC,
	GEANY_GBG_COUNT,
} GeanyBuildGroup;




/**
 * GeanyBuildSource: 
 * @GEANY_BCS_DEF:  Default values.
 * @GEANY_BCS_FT:  System filetype values.
 * @GEANY_BCS_HOME_FT:  Filetypes in ~/.config/geany/filedefs.
 * @GEANY_BCS_PREF:  Preferences file ~/.config/geany/geany.conf.
 * @GEANY_BCS_PROJ_FT:  Project file filetype command.
 * @GEANY_BCS_PROJ:  Project file if open.
 * @GEANY_BCS_COUNT:  Count of sources.
 *
 * 
 * Build menu item sources in increasing priority. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_BCS_DEF,
	GEANY_BCS_FT,
	GEANY_BCS_HOME_FT,
	GEANY_BCS_PREF,
	GEANY_BCS_PROJ_FT,
	GEANY_BCS_PROJ,
	GEANY_BCS_COUNT,
} GeanyBuildSource;




/**
 * GeanyBuildCmdEntries: 
 * @GEANY_BC_LABEL:  The menu item label, _ marks mnemonic.
 * @GEANY_BC_COMMAND:  The command to run.
 * @GEANY_BC_WORKING_DIR:  The directory to run in.
 * @GEANY_BC_CMDENTRIES_COUNT:  Count of entries.
 *
 * 
 * The entries of a command for a menu item. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_BC_LABEL,
	GEANY_BC_COMMAND,
	GEANY_BC_WORKING_DIR,
	GEANY_BC_CMDENTRIES_COUNT,
} GeanyBuildCmdEntries;




/**
 * GeanyIndentType: 
 * @GEANY_INDENT_TYPE_SPACES:  Spaces.
 * @GEANY_INDENT_TYPE_TABS:  Tabs.
 * @GEANY_INDENT_TYPE_BOTH:  Both.
 *
 * 
 * Whether to use tabs, spaces or both to indent. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_INDENT_TYPE_SPACES,
	GEANY_INDENT_TYPE_TABS,
	GEANY_INDENT_TYPE_BOTH,
} GeanyIndentType;




/**
 * GeanyAutoIndent: 
 * @GEANY_AUTOINDENT_NONE:  
 * @GEANY_AUTOINDENT_BASIC:  
 * @GEANY_AUTOINDENT_CURRENTCHARS:  
 * @GEANY_AUTOINDENT_MATCHBRACES:  
 *
 * 
 * Auto indentation modes. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_AUTOINDENT_NONE = 0,
	GEANY_AUTOINDENT_BASIC,
	GEANY_AUTOINDENT_CURRENTCHARS,
	GEANY_AUTOINDENT_MATCHBRACES,
} GeanyAutoIndent;




/**
 * GeanyIndicator: 
 * @GEANY_INDICATOR_ERROR:  Indicator to highlight errors in the document text.
 * @GEANY_INDICATOR_SEARCH:  Indicator used to highlight search results in the document.
 * @GEANY_INDICATOR_SNIPPET:  
 *
 * 
 * Geany indicator types, can be used with Editor indicator functions to highlight text in the document. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_INDICATOR_ERROR = 0,
	GEANY_INDICATOR_SEARCH = 8,
	GEANY_INDICATOR_SNIPPET = 9,
} GeanyIndicator;




/**
 * GeanyEncodingIndex: 
 * @GEANY_ENCODING_ISO_8859_1:  
 * @GEANY_ENCODING_ISO_8859_2:  
 * @GEANY_ENCODING_ISO_8859_3:  
 * @GEANY_ENCODING_ISO_8859_4:  
 * @GEANY_ENCODING_ISO_8859_5:  
 * @GEANY_ENCODING_ISO_8859_6:  
 * @GEANY_ENCODING_ISO_8859_7:  
 * @GEANY_ENCODING_ISO_8859_8:  
 * @GEANY_ENCODING_ISO_8859_8_I:  
 * @GEANY_ENCODING_ISO_8859_9:  
 * @GEANY_ENCODING_ISO_8859_10:  
 * @GEANY_ENCODING_ISO_8859_13:  
 * @GEANY_ENCODING_ISO_8859_14:  
 * @GEANY_ENCODING_ISO_8859_15:  
 * @GEANY_ENCODING_ISO_8859_16:  
 * @GEANY_ENCODING_UTF_7:  
 * @GEANY_ENCODING_UTF_8:  
 * @GEANY_ENCODING_UTF_16LE:  
 * @GEANY_ENCODING_UTF_16BE:  
 * @GEANY_ENCODING_UCS_2LE:  
 * @GEANY_ENCODING_UCS_2BE:  
 * @GEANY_ENCODING_UTF_32LE:  
 * @GEANY_ENCODING_UTF_32BE:  
 * @GEANY_ENCODING_ARMSCII_8:  
 * @GEANY_ENCODING_BIG5:  
 * @GEANY_ENCODING_BIG5_HKSCS:  
 * @GEANY_ENCODING_CP_866:  
 * @GEANY_ENCODING_EUC_JP:  
 * @GEANY_ENCODING_EUC_KR:  
 * @GEANY_ENCODING_EUC_TW:  
 * @GEANY_ENCODING_GB18030:  
 * @GEANY_ENCODING_GB2312:  
 * @GEANY_ENCODING_GBK:  
 * @GEANY_ENCODING_GEOSTD8:  
 * @GEANY_ENCODING_HZ:  
 * @GEANY_ENCODING_IBM_850:  
 * @GEANY_ENCODING_IBM_852:  
 * @GEANY_ENCODING_IBM_855:  
 * @GEANY_ENCODING_IBM_857:  
 * @GEANY_ENCODING_IBM_862:  
 * @GEANY_ENCODING_IBM_864:  
 * @GEANY_ENCODING_ISO_2022_JP:  
 * @GEANY_ENCODING_ISO_2022_KR:  
 * @GEANY_ENCODING_ISO_IR_111:  
 * @GEANY_ENCODING_JOHAB:  
 * @GEANY_ENCODING_KOI8_R:  
 * @GEANY_ENCODING_KOI8_U:  
 * @GEANY_ENCODING_SHIFT_JIS:  
 * @GEANY_ENCODING_TCVN:  
 * @GEANY_ENCODING_TIS_620:  
 * @GEANY_ENCODING_UHC:  
 * @GEANY_ENCODING_VISCII:  
 * @GEANY_ENCODING_WINDOWS_1250:  
 * @GEANY_ENCODING_WINDOWS_1251:  
 * @GEANY_ENCODING_WINDOWS_1252:  
 * @GEANY_ENCODING_WINDOWS_1253:  
 * @GEANY_ENCODING_WINDOWS_1254:  
 * @GEANY_ENCODING_WINDOWS_1255:  
 * @GEANY_ENCODING_WINDOWS_1256:  
 * @GEANY_ENCODING_WINDOWS_1257:  
 * @GEANY_ENCODING_WINDOWS_1258:  
 * @GEANY_ENCODING_NONE:  
 * @GEANY_ENCODING_CP_932:  
 * @GEANY_ENCODINGS_MAX:  
 *
 * 
 * List of known and supported encodings. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_ENCODING_ISO_8859_1,
	GEANY_ENCODING_ISO_8859_2,
	GEANY_ENCODING_ISO_8859_3,
	GEANY_ENCODING_ISO_8859_4,
	GEANY_ENCODING_ISO_8859_5,
	GEANY_ENCODING_ISO_8859_6,
	GEANY_ENCODING_ISO_8859_7,
	GEANY_ENCODING_ISO_8859_8,
	GEANY_ENCODING_ISO_8859_8_I,
	GEANY_ENCODING_ISO_8859_9,
	GEANY_ENCODING_ISO_8859_10,
	GEANY_ENCODING_ISO_8859_13,
	GEANY_ENCODING_ISO_8859_14,
	GEANY_ENCODING_ISO_8859_15,
	GEANY_ENCODING_ISO_8859_16,
	GEANY_ENCODING_UTF_7,
	GEANY_ENCODING_UTF_8,
	GEANY_ENCODING_UTF_16LE,
	GEANY_ENCODING_UTF_16BE,
	GEANY_ENCODING_UCS_2LE,
	GEANY_ENCODING_UCS_2BE,
	GEANY_ENCODING_UTF_32LE,
	GEANY_ENCODING_UTF_32BE,
	GEANY_ENCODING_ARMSCII_8,
	GEANY_ENCODING_BIG5,
	GEANY_ENCODING_BIG5_HKSCS,
	GEANY_ENCODING_CP_866,
	GEANY_ENCODING_EUC_JP,
	GEANY_ENCODING_EUC_KR,
	GEANY_ENCODING_EUC_TW,
	GEANY_ENCODING_GB18030,
	GEANY_ENCODING_GB2312,
	GEANY_ENCODING_GBK,
	GEANY_ENCODING_GEOSTD8,
	GEANY_ENCODING_HZ,
	GEANY_ENCODING_IBM_850,
	GEANY_ENCODING_IBM_852,
	GEANY_ENCODING_IBM_855,
	GEANY_ENCODING_IBM_857,
	GEANY_ENCODING_IBM_862,
	GEANY_ENCODING_IBM_864,
	GEANY_ENCODING_ISO_2022_JP,
	GEANY_ENCODING_ISO_2022_KR,
	GEANY_ENCODING_ISO_IR_111,
	GEANY_ENCODING_JOHAB,
	GEANY_ENCODING_KOI8_R,
	GEANY_ENCODING_KOI8_U,
	GEANY_ENCODING_SHIFT_JIS,
	GEANY_ENCODING_TCVN,
	GEANY_ENCODING_TIS_620,
	GEANY_ENCODING_UHC,
	GEANY_ENCODING_VISCII,
	GEANY_ENCODING_WINDOWS_1250,
	GEANY_ENCODING_WINDOWS_1251,
	GEANY_ENCODING_WINDOWS_1252,
	GEANY_ENCODING_WINDOWS_1253,
	GEANY_ENCODING_WINDOWS_1254,
	GEANY_ENCODING_WINDOWS_1255,
	GEANY_ENCODING_WINDOWS_1256,
	GEANY_ENCODING_WINDOWS_1257,
	GEANY_ENCODING_WINDOWS_1258,
	GEANY_ENCODING_NONE,
	GEANY_ENCODING_CP_932,
	GEANY_ENCODINGS_MAX,
} GeanyEncodingIndex;




/**
 * GeanyFiletypeID: 
 * @GEANY_FILETYPES_NONE:  
 * @GEANY_FILETYPES_PHP:  
 * @GEANY_FILETYPES_BASIC:  
 * @GEANY_FILETYPES_MATLAB:  
 * @GEANY_FILETYPES_RUBY:  
 * @GEANY_FILETYPES_LUA:  
 * @GEANY_FILETYPES_FERITE:  
 * @GEANY_FILETYPES_YAML:  
 * @GEANY_FILETYPES_C:  
 * @GEANY_FILETYPES_NSIS:  
 * @GEANY_FILETYPES_GLSL:  
 * @GEANY_FILETYPES_PO:  
 * @GEANY_FILETYPES_MAKE:  
 * @GEANY_FILETYPES_TCL:  
 * @GEANY_FILETYPES_XML:  
 * @GEANY_FILETYPES_CSS:  
 * @GEANY_FILETYPES_REST:  
 * @GEANY_FILETYPES_HASKELL:  
 * @GEANY_FILETYPES_JAVA:  
 * @GEANY_FILETYPES_CAML:  
 * @GEANY_FILETYPES_AS:  
 * @GEANY_FILETYPES_R:  
 * @GEANY_FILETYPES_DIFF:  
 * @GEANY_FILETYPES_HTML:  
 * @GEANY_FILETYPES_PYTHON:  
 * @GEANY_FILETYPES_CS:  
 * @GEANY_FILETYPES_PERL:  
 * @GEANY_FILETYPES_VALA:  
 * @GEANY_FILETYPES_PASCAL:  
 * @GEANY_FILETYPES_LATEX:  
 * @GEANY_FILETYPES_ASM:  
 * @GEANY_FILETYPES_CONF:  
 * @GEANY_FILETYPES_HAXE:  
 * @GEANY_FILETYPES_CPP:  
 * @GEANY_FILETYPES_SH:  
 * @GEANY_FILETYPES_FORTRAN:  
 * @GEANY_FILETYPES_SQL:  
 * @GEANY_FILETYPES_F77:  
 * @GEANY_FILETYPES_DOCBOOK:  
 * @GEANY_FILETYPES_D:  
 * @GEANY_FILETYPES_JS:  
 * @GEANY_FILETYPES_VHDL:  
 * @GEANY_FILETYPES_ADA:  
 * @GEANY_FILETYPES_CMAKE:  
 * @GEANY_FILETYPES_MARKDOWN:  
 * @GEANY_FILETYPES_TXT2TAGS:  
 * @GEANY_FILETYPES_ABC:  
 * @GEANY_FILETYPES_VERILOG:  
 * @GEANY_FILETYPES_FORTH:  
 * @GEANY_FILETYPES_LISP:  
 * @GEANY_FILETYPES_ERLANG:  
 * @GEANY_FILETYPES_COBOL:  
 * @GEANY_FILETYPES_OBJECTIVEC:  
 * @GEANY_FILETYPES_ASCIIDOC:  
 * @GEANY_FILETYPES_ABAQUS:  
 * @GEANY_FILETYPES_BATCH:  
 * @GEANY_FILETYPES_POWERSHELL:  
 * @GEANY_FILETYPES_RUST:  
 * @GEANY_FILETYPES_COFFEESCRIPT:  
 * @GEANY_FILETYPES_GO:  
 * @GEANY_FILETYPES_ZEPHIR:  
 * @GEANY_MAX_BUILT_IN_FILETYPES:  
 *
 * 
 * IDs of known filetypes. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_FILETYPES_NONE = 0,
	GEANY_FILETYPES_PHP,
	GEANY_FILETYPES_BASIC,
	GEANY_FILETYPES_MATLAB,
	GEANY_FILETYPES_RUBY,
	GEANY_FILETYPES_LUA,
	GEANY_FILETYPES_FERITE,
	GEANY_FILETYPES_YAML,
	GEANY_FILETYPES_C,
	GEANY_FILETYPES_NSIS,
	GEANY_FILETYPES_GLSL,
	GEANY_FILETYPES_PO,
	GEANY_FILETYPES_MAKE,
	GEANY_FILETYPES_TCL,
	GEANY_FILETYPES_XML,
	GEANY_FILETYPES_CSS,
	GEANY_FILETYPES_REST,
	GEANY_FILETYPES_HASKELL,
	GEANY_FILETYPES_JAVA,
	GEANY_FILETYPES_CAML,
	GEANY_FILETYPES_AS,
	GEANY_FILETYPES_R,
	GEANY_FILETYPES_DIFF,
	GEANY_FILETYPES_HTML,
	GEANY_FILETYPES_PYTHON,
	GEANY_FILETYPES_CS,
	GEANY_FILETYPES_PERL,
	GEANY_FILETYPES_VALA,
	GEANY_FILETYPES_PASCAL,
	GEANY_FILETYPES_LATEX,
	GEANY_FILETYPES_ASM,
	GEANY_FILETYPES_CONF,
	GEANY_FILETYPES_HAXE,
	GEANY_FILETYPES_CPP,
	GEANY_FILETYPES_SH,
	GEANY_FILETYPES_FORTRAN,
	GEANY_FILETYPES_SQL,
	GEANY_FILETYPES_F77,
	GEANY_FILETYPES_DOCBOOK,
	GEANY_FILETYPES_D,
	GEANY_FILETYPES_JS,
	GEANY_FILETYPES_VHDL,
	GEANY_FILETYPES_ADA,
	GEANY_FILETYPES_CMAKE,
	GEANY_FILETYPES_MARKDOWN,
	GEANY_FILETYPES_TXT2TAGS,
	GEANY_FILETYPES_ABC,
	GEANY_FILETYPES_VERILOG,
	GEANY_FILETYPES_FORTH,
	GEANY_FILETYPES_LISP,
	GEANY_FILETYPES_ERLANG,
	GEANY_FILETYPES_COBOL,
	GEANY_FILETYPES_OBJECTIVEC,
	GEANY_FILETYPES_ASCIIDOC,
	GEANY_FILETYPES_ABAQUS,
	GEANY_FILETYPES_BATCH,
	GEANY_FILETYPES_POWERSHELL,
	GEANY_FILETYPES_RUST,
	GEANY_FILETYPES_COFFEESCRIPT,
	GEANY_FILETYPES_GO,
	GEANY_FILETYPES_ZEPHIR,
	GEANY_MAX_BUILT_IN_FILETYPES,
} GeanyFiletypeID;




/**
 * GeanyFiletypeGroupID: 
 * @GEANY_FILETYPE_GROUP_NONE:  
 * @GEANY_FILETYPE_GROUP_COMPILED:  
 * @GEANY_FILETYPE_GROUP_SCRIPT:  
 * @GEANY_FILETYPE_GROUP_MARKUP:  
 * @GEANY_FILETYPE_GROUP_MISC:  
 * @GEANY_FILETYPE_GROUP_COUNT:  
 *
 * 
 * Filetype categories. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_FILETYPE_GROUP_NONE,
	GEANY_FILETYPE_GROUP_COMPILED,
	GEANY_FILETYPE_GROUP_SCRIPT,
	GEANY_FILETYPE_GROUP_MARKUP,
	GEANY_FILETYPE_GROUP_MISC,
	GEANY_FILETYPE_GROUP_COUNT,
} GeanyFiletypeGroupID;




/**
 * GeanyKeyGroupID: 
 * @GEANY_KEY_GROUP_FILE:  Group.
 * @GEANY_KEY_GROUP_PROJECT:  Group.
 * @GEANY_KEY_GROUP_EDITOR:  Group.
 * @GEANY_KEY_GROUP_CLIPBOARD:  Group.
 * @GEANY_KEY_GROUP_SELECT:  Group.
 * @GEANY_KEY_GROUP_FORMAT:  Group.
 * @GEANY_KEY_GROUP_INSERT:  Group.
 * @GEANY_KEY_GROUP_SETTINGS:  Group.
 * @GEANY_KEY_GROUP_SEARCH:  Group.
 * @GEANY_KEY_GROUP_GOTO:  Group.
 * @GEANY_KEY_GROUP_VIEW:  Group.
 * @GEANY_KEY_GROUP_FOCUS:  Group.
 * @GEANY_KEY_GROUP_NOTEBOOK:  Group.
 * @GEANY_KEY_GROUP_DOCUMENT:  Group.
 * @GEANY_KEY_GROUP_BUILD:  Group.
 * @GEANY_KEY_GROUP_TOOLS:  Group.
 * @GEANY_KEY_GROUP_HELP:  Group.
 * @GEANY_KEY_GROUP_COUNT:  
 *
 * 
 * Keybinding group IDs for use with keybindings_send_command(). 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_KEY_GROUP_FILE,
	GEANY_KEY_GROUP_PROJECT,
	GEANY_KEY_GROUP_EDITOR,
	GEANY_KEY_GROUP_CLIPBOARD,
	GEANY_KEY_GROUP_SELECT,
	GEANY_KEY_GROUP_FORMAT,
	GEANY_KEY_GROUP_INSERT,
	GEANY_KEY_GROUP_SETTINGS,
	GEANY_KEY_GROUP_SEARCH,
	GEANY_KEY_GROUP_GOTO,
	GEANY_KEY_GROUP_VIEW,
	GEANY_KEY_GROUP_FOCUS,
	GEANY_KEY_GROUP_NOTEBOOK,
	GEANY_KEY_GROUP_DOCUMENT,
	GEANY_KEY_GROUP_BUILD,
	GEANY_KEY_GROUP_TOOLS,
	GEANY_KEY_GROUP_HELP,
	GEANY_KEY_GROUP_COUNT,
} GeanyKeyGroupID;




/**
 * GeanyKeyBindingID: 
 * @GEANY_KEYS_EDITOR_TRANSPOSELINE:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_REMOVE_ERROR_INDICATORS:  Keybinding.
 * @GEANY_KEYS_FOCUS_SEARCHBAR:  Keybinding.
 * @GEANY_KEYS_SEARCH_FIND:  Keybinding.
 * @GEANY_KEYS_FILE_SAVEALL:  Keybinding.
 * @GEANY_KEYS_GOTO_NEXTMARKER:  Keybinding.
 * @GEANY_KEYS_NOTEBOOK_SWITCHTABLEFT:  Keybinding.
 * @GEANY_KEYS_VIEW_ZOOMOUT:  Keybinding.
 * @GEANY_KEYS_GOTO_LINE:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_TOGGLEFOLD:  Keybinding.
 * @GEANY_KEYS_BUILD_COMPILE:  Keybinding.
 * @GEANY_KEYS_EDITOR_SCROLLTOLINE:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_UNFOLDALL:  Keybinding.
 * @GEANY_KEYS_GOTO_MATCHINGBRACE:  Keybinding.
 * @GEANY_KEYS_SEARCH_FINDDOCUMENTUSAGE:  Keybinding.
 * @GEANY_KEYS_CLIPBOARD_PASTE:  Keybinding.
 * @GEANY_KEYS_BUILD_MAKE:  Keybinding.
 * @GEANY_KEYS_INSERT_ALTWHITESPACE:  Keybinding.
 * @GEANY_KEYS_EDITOR_SCROLLLINEDOWN:  Keybinding.
 * @GEANY_KEYS_VIEW_TOGGLEALL:  Keybinding.
 * @GEANY_KEYS_VIEW_FULLSCREEN:  Keybinding.
 * @GEANY_KEYS_GOTO_LINEEND:  Keybinding.
 * @GEANY_KEYS_EDITOR_CALLTIP:  Keybinding.
 * @GEANY_KEYS_FILE_PRINT:  Keybinding.
 * @GEANY_KEYS_EDITOR_DUPLICATELINE:  Keybinding.
 * @GEANY_KEYS_FOCUS_SCRIBBLE:  Keybinding.
 * @GEANY_KEYS_TOOLS_OPENCOLORCHOOSER:  Keybinding.
 * @GEANY_KEYS_SEARCH_PREVIOUSMESSAGE:  Keybinding.
 * @GEANY_KEYS_FILE_CLOSE:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_REPLACETABS:  Keybinding.
 * @GEANY_KEYS_FILE_RELOAD:  Keybinding.
 * @GEANY_KEYS_SEARCH_FINDNEXTSEL:  Keybinding.
 * @GEANY_KEYS_FOCUS_MESSAGES:  Keybinding.
 * @GEANY_KEYS_BUILD_RUN:  Keybinding.
 * @GEANY_KEYS_HELP_HELP:  Keybinding.
 * @GEANY_KEYS_SETTINGS_PLUGINPREFERENCES:  Keybinding.
 * @GEANY_KEYS_VIEW_ZOOMRESET:  Keybinding.
 * @GEANY_KEYS_SELECT_WORD:  Keybinding.
 * @GEANY_KEYS_FORMAT_INCREASEINDENT:  Keybinding.
 * @GEANY_KEYS_SETTINGS_PREFERENCES:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD3:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_FOLDALL:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOVTE:  Keybinding.
 * @GEANY_KEYS_PROJECT_PROPERTIES:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_LINEWRAP:  Keybinding.
 * @GEANY_KEYS_EDITOR_MACROLIST:  Keybinding.
 * @GEANY_KEYS_EDITOR_SUPPRESSSNIPPETCOMPLETION:  Keybinding.
 * @GEANY_KEYS_FOCUS_SIDEBAR_SYMBOL_LIST:  Keybinding.
 * @GEANY_KEYS_GOTO_LINESTART:  Keybinding.
 * @GEANY_KEYS_SEARCH_FINDUSAGE:  Keybinding.
 * @GEANY_KEYS_FILE_NEW:  Keybinding.
 * @GEANY_KEYS_EDITOR_SNIPPETNEXTCURSOR:  Keybinding.
 * @GEANY_KEYS_NOTEBOOK_SWITCHTABRIGHT:  Keybinding.
 * @GEANY_KEYS_FILE_SAVE:  Keybinding.
 * @GEANY_KEYS_FORMAT_INCREASEINDENTBYSPACE:  Keybinding.
 * @GEANY_KEYS_SEARCH_FINDNEXT:  Keybinding.
 * @GEANY_KEYS_GOTO_TOGGLEMARKER:  Keybinding.
 * @GEANY_KEYS_GOTO_TAGDEFINITION:  Keybinding.
 * @GEANY_KEYS_SEARCH_NEXTMESSAGE:  Keybinding.
 * @GEANY_KEYS_EDITOR_DELETELINETOEND:  Keybinding.
 * @GEANY_KEYS_FORMAT_AUTOINDENT:  Keybinding.
 * @GEANY_KEYS_FILE_OPENSELECTED:  Keybinding.
 * @GEANY_KEYS_GOTO_BACK:  Keybinding.
 * @GEANY_KEYS_INSERT_DATE:  Keybinding.
 * @GEANY_KEYS_BUILD_PREVIOUSERROR:  Keybinding.
 * @GEANY_KEYS_GOTO_LINEENDVISUAL:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_REPLACESPACES:  Keybinding.
 * @GEANY_KEYS_FOCUS_EDITOR:  Keybinding.
 * @GEANY_KEYS_SELECT_WORDPARTRIGHT:  Keybinding.
 * @GEANY_KEYS_VIEW_MESSAGEWINDOW:  Keybinding.
 * @GEANY_KEYS_FOCUS_SIDEBAR_DOCUMENT_LIST:  Keybinding.
 * @GEANY_KEYS_FORMAT_REFLOWPARAGRAPH:  Keybinding.
 * @GEANY_KEYS_EDITOR_MOVELINEUP:  Keybinding.
 * @GEANY_KEYS_NOTEBOOK_MOVETABLEFT:  Keybinding.
 * @GEANY_KEYS_SELECT_LINE:  Keybinding.
 * @GEANY_KEYS_EDITOR_UNDO:  Keybinding.
 * @GEANY_KEYS_EDITOR_MOVELINEDOWN:  Keybinding.
 * @GEANY_KEYS_CLIPBOARD_COPYLINE:  Keybinding.
 * @GEANY_KEYS_BUILD_MAKEOWNTARGET:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD2:  Keybinding.
 * @GEANY_KEYS_SEARCH_MARKALL:  Keybinding.
 * @GEANY_KEYS_BUILD_LINK:  Keybinding.
 * @GEANY_KEYS_FILE_CLOSEALL:  Keybinding.
 * @GEANY_KEYS_GOTO_FORWARD:  Keybinding.
 * @GEANY_KEYS_CLIPBOARD_CUT:  Keybinding.
 * @GEANY_KEYS_NOTEBOOK_SWITCHTABLASTUSED:  Keybinding.
 * @GEANY_KEYS_NOTEBOOK_MOVETABRIGHT:  Keybinding.
 * @GEANY_KEYS_BUILD_OPTIONS:  Keybinding.
 * @GEANY_KEYS_GOTO_TAGDECLARATION:  Keybinding.
 * @GEANY_KEYS_FILE_OPEN:  Keybinding.
 * @GEANY_KEYS_EDITOR_COMPLETESNIPPET:  Keybinding.
 * @GEANY_KEYS_FORMAT_UNCOMMENTLINE:  Keybinding.
 * @GEANY_KEYS_FOCUS_VTE:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD1:  Keybinding.
 * @GEANY_KEYS_SELECT_WORDPARTLEFT:  Keybinding.
 * @GEANY_KEYS_VIEW_ZOOMIN:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_LINEBREAK:  Keybinding.
 * @GEANY_KEYS_EDITOR_REDO:  Keybinding.
 * @GEANY_KEYS_EDITOR_CONTEXTACTION:  Keybinding.
 * @GEANY_KEYS_SEARCH_FINDPREVSEL:  Keybinding.
 * @GEANY_KEYS_FORMAT_DECREASEINDENTBYSPACE:  Keybinding.
 * @GEANY_KEYS_FORMAT_COMMENTLINETOGGLE:  Keybinding.
 * @GEANY_KEYS_SELECT_ALL:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_RELOADTAGLIST:  Keybinding.
 * @GEANY_KEYS_BUILD_NEXTERROR:  Keybinding.
 * @GEANY_KEYS_NOTEBOOK_MOVETABLAST:  Keybinding.
 * @GEANY_KEYS_SELECT_PARAGRAPH:  Keybinding.
 * @GEANY_KEYS_EDITOR_DELETELINE:  Keybinding.
 * @GEANY_KEYS_CLIPBOARD_COPY:  Keybinding.
 * @GEANY_KEYS_VIEW_SIDEBAR:  Keybinding.
 * @GEANY_KEYS_FILE_SAVEAS:  Keybinding.
 * @GEANY_KEYS_FORMAT_COMMENTLINE:  Keybinding.
 * @GEANY_KEYS_GOTO_PREVWORDPART:  Keybinding.
 * @GEANY_KEYS_SEARCH_FINDPREVIOUS:  Keybinding.
 * @GEANY_KEYS_SEARCH_REPLACE:  Keybinding.
 * @GEANY_KEYS_EDITOR_WORDPARTCOMPLETION:  Keybinding.
 * @GEANY_KEYS_EDITOR_AUTOCOMPLETE:  Keybinding.
 * @GEANY_KEYS_FOCUS_SIDEBAR:  Keybinding.
 * @GEANY_KEYS_FOCUS_MESSAGE_WINDOW:  Keybinding.
 * @GEANY_KEYS_NOTEBOOK_MOVETABFIRST:  Keybinding.
 * @GEANY_KEYS_GOTO_PREVIOUSMARKER:  Keybinding.
 * @GEANY_KEYS_EDITOR_SCROLLLINEUP:  Keybinding.
 * @GEANY_KEYS_FOCUS_COMPILER:  Keybinding.
 * @GEANY_KEYS_FORMAT_TOGGLECASE:  Keybinding.
 * @GEANY_KEYS_CLIPBOARD_CUTLINE:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_REMOVE_MARKERS:  Keybinding.
 * @GEANY_KEYS_BUILD_MAKEOBJECT:  Keybinding.
 * @GEANY_KEYS_FORMAT_DECREASEINDENT:  Keybinding.
 * @GEANY_KEYS_FILE_OPENLASTTAB:  Keybinding.
 * @GEANY_KEYS_SEARCH_FINDINFILES:  Keybinding.
 * @GEANY_KEYS_GOTO_NEXTWORDPART:  Keybinding.
 * @GEANY_KEYS_INSERT_LINEAFTER:  Keybinding.
 * @GEANY_KEYS_INSERT_LINEBEFORE:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_REMOVE_MARKERS_INDICATORS:  Keybinding.
 * @GEANY_KEYS_PROJECT_OPEN:  Keybinding.
 * @GEANY_KEYS_PROJECT_NEW:  Keybinding.
 * @GEANY_KEYS_PROJECT_CLOSE:  Keybinding.
 * @GEANY_KEYS_FORMAT_JOINLINES:  Keybinding.
 * @GEANY_KEYS_GOTO_LINESTARTVISUAL:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_CLONE:  Keybinding.
 * @GEANY_KEYS_FILE_QUIT:  Keybinding.
 * @GEANY_KEYS_FILE_PROPERTIES:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD4:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD5:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD6:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD7:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD8:  Keybinding.
 * @GEANY_KEYS_FORMAT_SENDTOCMD9:  Keybinding.
 * @GEANY_KEYS_EDITOR_DELETELINETOBEGINNING:  Keybinding.
 * @GEANY_KEYS_DOCUMENT_STRIPTRAILINGSPACES:  Keybinding.
 * @GEANY_KEYS_COUNT:  
 *
 * 
 * Keybinding command IDs for use with keybindings_send_command(). 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_KEYS_EDITOR_TRANSPOSELINE,
	GEANY_KEYS_DOCUMENT_REMOVE_ERROR_INDICATORS,
	GEANY_KEYS_FOCUS_SEARCHBAR,
	GEANY_KEYS_SEARCH_FIND,
	GEANY_KEYS_FILE_SAVEALL,
	GEANY_KEYS_GOTO_NEXTMARKER,
	GEANY_KEYS_NOTEBOOK_SWITCHTABLEFT,
	GEANY_KEYS_VIEW_ZOOMOUT,
	GEANY_KEYS_GOTO_LINE,
	GEANY_KEYS_DOCUMENT_TOGGLEFOLD,
	GEANY_KEYS_BUILD_COMPILE,
	GEANY_KEYS_EDITOR_SCROLLTOLINE,
	GEANY_KEYS_DOCUMENT_UNFOLDALL,
	GEANY_KEYS_GOTO_MATCHINGBRACE,
	GEANY_KEYS_SEARCH_FINDDOCUMENTUSAGE,
	GEANY_KEYS_CLIPBOARD_PASTE,
	GEANY_KEYS_BUILD_MAKE,
	GEANY_KEYS_INSERT_ALTWHITESPACE,
	GEANY_KEYS_EDITOR_SCROLLLINEDOWN,
	GEANY_KEYS_VIEW_TOGGLEALL,
	GEANY_KEYS_VIEW_FULLSCREEN,
	GEANY_KEYS_GOTO_LINEEND,
	GEANY_KEYS_EDITOR_CALLTIP,
	GEANY_KEYS_FILE_PRINT,
	GEANY_KEYS_EDITOR_DUPLICATELINE,
	GEANY_KEYS_FOCUS_SCRIBBLE,
	GEANY_KEYS_TOOLS_OPENCOLORCHOOSER,
	GEANY_KEYS_SEARCH_PREVIOUSMESSAGE,
	GEANY_KEYS_FILE_CLOSE,
	GEANY_KEYS_DOCUMENT_REPLACETABS,
	GEANY_KEYS_FILE_RELOAD,
	GEANY_KEYS_SEARCH_FINDNEXTSEL,
	GEANY_KEYS_FOCUS_MESSAGES,
	GEANY_KEYS_BUILD_RUN,
	GEANY_KEYS_HELP_HELP,
	GEANY_KEYS_SETTINGS_PLUGINPREFERENCES,
	GEANY_KEYS_VIEW_ZOOMRESET,
	GEANY_KEYS_SELECT_WORD,
	GEANY_KEYS_FORMAT_INCREASEINDENT,
	GEANY_KEYS_SETTINGS_PREFERENCES,
	GEANY_KEYS_FORMAT_SENDTOCMD3,
	GEANY_KEYS_DOCUMENT_FOLDALL,
	GEANY_KEYS_FORMAT_SENDTOVTE,
	GEANY_KEYS_PROJECT_PROPERTIES,
	GEANY_KEYS_DOCUMENT_LINEWRAP,
	GEANY_KEYS_EDITOR_MACROLIST,
	GEANY_KEYS_EDITOR_SUPPRESSSNIPPETCOMPLETION,
	GEANY_KEYS_FOCUS_SIDEBAR_SYMBOL_LIST,
	GEANY_KEYS_GOTO_LINESTART,
	GEANY_KEYS_SEARCH_FINDUSAGE,
	GEANY_KEYS_FILE_NEW,
	GEANY_KEYS_EDITOR_SNIPPETNEXTCURSOR,
	GEANY_KEYS_NOTEBOOK_SWITCHTABRIGHT,
	GEANY_KEYS_FILE_SAVE,
	GEANY_KEYS_FORMAT_INCREASEINDENTBYSPACE,
	GEANY_KEYS_SEARCH_FINDNEXT,
	GEANY_KEYS_GOTO_TOGGLEMARKER,
	GEANY_KEYS_GOTO_TAGDEFINITION,
	GEANY_KEYS_SEARCH_NEXTMESSAGE,
	GEANY_KEYS_EDITOR_DELETELINETOEND,
	GEANY_KEYS_FORMAT_AUTOINDENT,
	GEANY_KEYS_FILE_OPENSELECTED,
	GEANY_KEYS_GOTO_BACK,
	GEANY_KEYS_INSERT_DATE,
	GEANY_KEYS_BUILD_PREVIOUSERROR,
	GEANY_KEYS_GOTO_LINEENDVISUAL,
	GEANY_KEYS_DOCUMENT_REPLACESPACES,
	GEANY_KEYS_FOCUS_EDITOR,
	GEANY_KEYS_SELECT_WORDPARTRIGHT,
	GEANY_KEYS_VIEW_MESSAGEWINDOW,
	GEANY_KEYS_FOCUS_SIDEBAR_DOCUMENT_LIST,
	GEANY_KEYS_FORMAT_REFLOWPARAGRAPH,
	GEANY_KEYS_EDITOR_MOVELINEUP,
	GEANY_KEYS_NOTEBOOK_MOVETABLEFT,
	GEANY_KEYS_SELECT_LINE,
	GEANY_KEYS_EDITOR_UNDO,
	GEANY_KEYS_EDITOR_MOVELINEDOWN,
	GEANY_KEYS_CLIPBOARD_COPYLINE,
	GEANY_KEYS_BUILD_MAKEOWNTARGET,
	GEANY_KEYS_FORMAT_SENDTOCMD2,
	GEANY_KEYS_SEARCH_MARKALL,
	GEANY_KEYS_BUILD_LINK,
	GEANY_KEYS_FILE_CLOSEALL,
	GEANY_KEYS_GOTO_FORWARD,
	GEANY_KEYS_CLIPBOARD_CUT,
	GEANY_KEYS_NOTEBOOK_SWITCHTABLASTUSED,
	GEANY_KEYS_NOTEBOOK_MOVETABRIGHT,
	GEANY_KEYS_BUILD_OPTIONS,
	GEANY_KEYS_GOTO_TAGDECLARATION,
	GEANY_KEYS_FILE_OPEN,
	GEANY_KEYS_EDITOR_COMPLETESNIPPET,
	GEANY_KEYS_FORMAT_UNCOMMENTLINE,
	GEANY_KEYS_FOCUS_VTE,
	GEANY_KEYS_FORMAT_SENDTOCMD1,
	GEANY_KEYS_SELECT_WORDPARTLEFT,
	GEANY_KEYS_VIEW_ZOOMIN,
	GEANY_KEYS_DOCUMENT_LINEBREAK,
	GEANY_KEYS_EDITOR_REDO,
	GEANY_KEYS_EDITOR_CONTEXTACTION,
	GEANY_KEYS_SEARCH_FINDPREVSEL,
	GEANY_KEYS_FORMAT_DECREASEINDENTBYSPACE,
	GEANY_KEYS_FORMAT_COMMENTLINETOGGLE,
	GEANY_KEYS_SELECT_ALL,
	GEANY_KEYS_DOCUMENT_RELOADTAGLIST,
	GEANY_KEYS_BUILD_NEXTERROR,
	GEANY_KEYS_NOTEBOOK_MOVETABLAST,
	GEANY_KEYS_SELECT_PARAGRAPH,
	GEANY_KEYS_EDITOR_DELETELINE,
	GEANY_KEYS_CLIPBOARD_COPY,
	GEANY_KEYS_VIEW_SIDEBAR,
	GEANY_KEYS_FILE_SAVEAS,
	GEANY_KEYS_FORMAT_COMMENTLINE,
	GEANY_KEYS_GOTO_PREVWORDPART,
	GEANY_KEYS_SEARCH_FINDPREVIOUS,
	GEANY_KEYS_SEARCH_REPLACE,
	GEANY_KEYS_EDITOR_WORDPARTCOMPLETION,
	GEANY_KEYS_EDITOR_AUTOCOMPLETE,
	GEANY_KEYS_FOCUS_SIDEBAR,
	GEANY_KEYS_FOCUS_MESSAGE_WINDOW,
	GEANY_KEYS_NOTEBOOK_MOVETABFIRST,
	GEANY_KEYS_GOTO_PREVIOUSMARKER,
	GEANY_KEYS_EDITOR_SCROLLLINEUP,
	GEANY_KEYS_FOCUS_COMPILER,
	GEANY_KEYS_FORMAT_TOGGLECASE,
	GEANY_KEYS_CLIPBOARD_CUTLINE,
	GEANY_KEYS_DOCUMENT_REMOVE_MARKERS,
	GEANY_KEYS_BUILD_MAKEOBJECT,
	GEANY_KEYS_FORMAT_DECREASEINDENT,
	GEANY_KEYS_FILE_OPENLASTTAB,
	GEANY_KEYS_SEARCH_FINDINFILES,
	GEANY_KEYS_GOTO_NEXTWORDPART,
	GEANY_KEYS_INSERT_LINEAFTER,
	GEANY_KEYS_INSERT_LINEBEFORE,
	GEANY_KEYS_DOCUMENT_REMOVE_MARKERS_INDICATORS,
	GEANY_KEYS_PROJECT_OPEN,
	GEANY_KEYS_PROJECT_NEW,
	GEANY_KEYS_PROJECT_CLOSE,
	GEANY_KEYS_FORMAT_JOINLINES,
	GEANY_KEYS_GOTO_LINESTARTVISUAL,
	GEANY_KEYS_DOCUMENT_CLONE,
	GEANY_KEYS_FILE_QUIT,
	GEANY_KEYS_FILE_PROPERTIES,
	GEANY_KEYS_FORMAT_SENDTOCMD4,
	GEANY_KEYS_FORMAT_SENDTOCMD5,
	GEANY_KEYS_FORMAT_SENDTOCMD6,
	GEANY_KEYS_FORMAT_SENDTOCMD7,
	GEANY_KEYS_FORMAT_SENDTOCMD8,
	GEANY_KEYS_FORMAT_SENDTOCMD9,
	GEANY_KEYS_EDITOR_DELETELINETOBEGINNING,
	GEANY_KEYS_DOCUMENT_STRIPTRAILINGSPACES,
	GEANY_KEYS_COUNT,
} GeanyKeyBindingID;




/**
 * MsgColors: 
 * @COLOR_RED:  Color red.
 * @COLOR_DARK_RED:  Color dark red.
 * @COLOR_BLACK:  Color black.
 * @COLOR_BLUE:  Color blue.
 *
 * 
 * Various colors for use in the compiler and messages treeviews when adding messages. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	COLOR_RED,
	COLOR_DARK_RED,
	COLOR_BLACK,
	COLOR_BLUE,
} MsgColors;




/**
 * MessageWindowTabNum: 
 * @MSG_STATUS:  Index of the status message tab.
 * @MSG_COMPILER:  Index of the compiler tab.
 * @MSG_MESSAGE:  Index of the messages tab.
 * @MSG_SCRATCH:  Index of the scratch tab.
 * @MSG_VTE:  Index of the VTE tab.
 *
 * 
 * Indices of the notebooks in the messages window. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	MSG_STATUS = 0,
	MSG_COMPILER,
	MSG_MESSAGE,
	MSG_SCRATCH,
	MSG_VTE,
} MessageWindowTabNum;




/**
 * GeanyProxyProbeResults: 
 * @GEANY_PROXY_IGNORE:  The proxy is not responsible at all, and Geany or other plugins are free to probe it.
 * @GEANY_PROXY_MATCH:  The proxy is responsible for this file, and creates a plugin for it.
 * @GEANY_PROXY_RELATED:  The proxy is does not directly load it, but it's still tied to the proxy.
 *
 * 
 * Return values for GeanyProxyHooks::probe() 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_PROXY_IGNORE,
	GEANY_PROXY_MATCH,
	GEANY_PROXY_RELATED = GEANY_PROXY_MATCH | 0x100,
} GeanyProxyProbeResults;




/**
 * GeanyFindSelOptions: 
 * @GEANY_FIND_SEL_CURRENT_WORD:  
 * @GEANY_FIND_SEL_X:  
 * @GEANY_FIND_SEL_AGAIN:  
 *
 * 
 * Find selection options. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	GEANY_FIND_SEL_CURRENT_WORD,
	GEANY_FIND_SEL_X,
	GEANY_FIND_SEL_AGAIN,
} GeanyFindSelOptions;




/**
 * SpawnFlags: 
 * @SPAWN_ASYNC:  Asynchronous execution [default].
 * @SPAWN_SYNC:  Synchronous execution.
 * @SPAWN_LINE_BUFFERED:  stdout/stderr are line buffered [default].
 * @SPAWN_STDOUT_UNBUFFERED:  stdout is not buffered.
 * @SPAWN_STDERR_UNBUFFERED:  stderr is not buffered.
 * @SPAWN_UNBUFFERED:  stdout/stderr are not buffered.
 * @SPAWN_STDIN_RECURSIVE:  The stdin callback is recursive.
 * @SPAWN_STDOUT_RECURSIVE:  The stdout callback is recursive.
 * @SPAWN_STDERR_RECURSIVE:  The stderr callback is recursive.
 * @SPAWN_RECURSIVE:  All callbacks are recursive.
 *
 * 
 * Flags passed to spawn_with_callbacks(), which see. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	SPAWN_ASYNC = 0x00,
	SPAWN_SYNC = 0x01,
	SPAWN_LINE_BUFFERED = 0x00,
	SPAWN_STDOUT_UNBUFFERED = 0x02,
	SPAWN_STDERR_UNBUFFERED = 0x04,
	SPAWN_UNBUFFERED = 0x06,
	SPAWN_STDIN_RECURSIVE = 0x08,
	SPAWN_STDOUT_RECURSIVE = 0x10,
	SPAWN_STDERR_RECURSIVE = 0x20,
	SPAWN_RECURSIVE = 0x38,
} SpawnFlags;




/**
 * TMTagType: 
 * @tm_tag_undef_t:  Unknown type.
 * @tm_tag_class_t:  Class declaration.
 * @tm_tag_enum_t:  Enum declaration.
 * @tm_tag_enumerator_t:  Enumerator value.
 * @tm_tag_field_t:  Field (Java only)
 * @tm_tag_function_t:  Function definition.
 * @tm_tag_interface_t:  Interface (Java only)
 * @tm_tag_member_t:  Member variable of class/struct.
 * @tm_tag_method_t:  Class method (Java only)
 * @tm_tag_namespace_t:  Namespace declaration.
 * @tm_tag_package_t:  Package (Java only)
 * @tm_tag_prototype_t:  Function prototype.
 * @tm_tag_struct_t:  Struct declaration.
 * @tm_tag_typedef_t:  Typedef.
 * @tm_tag_union_t:  Union.
 * @tm_tag_variable_t:  Variable.
 * @tm_tag_externvar_t:  Extern or forward declaration.
 * @tm_tag_macro_t:  Macro (without arguments)
 * @tm_tag_macro_with_arg_t:  Parameterized macro.
 * @tm_tag_file_t:  File (Pseudo tag) - obsolete.
 * @tm_tag_other_t:  Other (non C/C++/Java tag)
 * @tm_tag_max_t:  Maximum value of TMTagType.
 *
 * 
 * Types of tags. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	tm_tag_undef_t = 0,
	tm_tag_class_t = 1,
	tm_tag_enum_t = 2,
	tm_tag_enumerator_t = 4,
	tm_tag_field_t = 8,
	tm_tag_function_t = 16,
	tm_tag_interface_t = 32,
	tm_tag_member_t = 64,
	tm_tag_method_t = 128,
	tm_tag_namespace_t = 256,
	tm_tag_package_t = 512,
	tm_tag_prototype_t = 1024,
	tm_tag_struct_t = 2048,
	tm_tag_typedef_t = 4096,
	tm_tag_union_t = 8192,
	tm_tag_variable_t = 16384,
	tm_tag_externvar_t = 32768,
	tm_tag_macro_t = 65536,
	tm_tag_macro_with_arg_t = 131072,
	tm_tag_file_t = 262144,
	tm_tag_other_t = 524288,
	tm_tag_max_t = 1048575,
} TMTagType;




/**
 * TMTagAttrType: 
 * @tm_tag_attr_none_t:  Undefined.
 * @tm_tag_attr_name_t:  Tag Name.
 * @tm_tag_attr_type_t:  Tag Type.
 * @tm_tag_attr_file_t:  File in which tag exists.
 * @tm_tag_attr_line_t:  Line number of tag.
 * @tm_tag_attr_pos_t:  Byte position of tag in the file (Obsolete)
 * @tm_tag_attr_scope_t:  Scope of the tag.
 * @tm_tag_attr_inheritance_t:  Parent classes.
 * @tm_tag_attr_arglist_t:  Argument list.
 * @tm_tag_attr_local_t:  If it has local scope.
 * @tm_tag_attr_time_t:  Modification time (File tag only)
 * @tm_tag_attr_vartype_t:  Variable Type.
 * @tm_tag_attr_access_t:  Access type (public/protected/private)
 * @tm_tag_attr_impl_t:  Implementation (e.g.
 * @tm_tag_attr_lang_t:  Language (File tag only)
 * @tm_tag_attr_inactive_t:  Inactive file (File tag only, obsolete)
 * @tm_tag_attr_pointer_t:  Pointer type.
 * @tm_tag_attr_max_t:  Maximum value.
 *
 * 
 * Tag Attributes. 
 * 
 *         
 *
 * 
 *
 */
typedef enum {
	tm_tag_attr_none_t = 0,
	tm_tag_attr_name_t = 1,
	tm_tag_attr_type_t = 2,
	tm_tag_attr_file_t = 4,
	tm_tag_attr_line_t = 8,
	tm_tag_attr_pos_t = 16,
	tm_tag_attr_scope_t = 32,
	tm_tag_attr_inheritance_t = 64,
	tm_tag_attr_arglist_t = 128,
	tm_tag_attr_local_t = 256,
	tm_tag_attr_time_t = 512,
	tm_tag_attr_vartype_t = 1024,
	tm_tag_attr_access_t = 2048,
	tm_tag_attr_impl_t = 4096,
	tm_tag_attr_lang_t = 8192,
	tm_tag_attr_inactive_t = 16384,
	tm_tag_attr_pointer_t = 32768,
	tm_tag_attr_max_t = 65535,
} TMTagAttrType;


typedef struct GeanyApp GeanyApp;

typedef struct GeanyFilePrefs GeanyFilePrefs;

typedef struct GeanyDocument GeanyDocument;

typedef struct GeanyIndentPrefs GeanyIndentPrefs;

typedef struct GeanyEditorPrefs GeanyEditorPrefs;

typedef struct GeanyEditor GeanyEditor;

typedef GeanyFiletypeID filetype_id;

typedef struct GeanyFiletype GeanyFiletype;

typedef struct _GeanyEntryAction GeanyEntryAction;

typedef struct _GeanyEntryActionClass GeanyEntryActionClass;

typedef struct _GeanyMenubuttonAction GeanyMenubuttonAction;

typedef struct _GeanyMenubuttonActionClass GeanyMenubuttonActionClass;

typedef struct _GeanyObject GeanyObject;

typedef struct _GeanyObjectClass GeanyObjectClass;

typedef struct _GeanyWrapLabel GeanyWrapLabel;

typedef struct _GeanyWrapLabelClass GeanyWrapLabelClass;

typedef struct GeanyLexerStyle GeanyLexerStyle;

typedef struct GeanyKeyGroup GeanyKeyGroup;

typedef struct GeanyKeyBinding GeanyKeyBinding;

typedef gboolean(* GeanyKeyGroupCallback) (guint key_id);

typedef gboolean(* GeanyKeyGroupFunc) (GeanyKeyGroup *group, guint key_id, gpointer user_data);

typedef void(* GeanyKeyCallback) (guint key_id);

typedef gboolean(* GeanyKeyBindingFunc) (GeanyKeyBinding *key, guint key_id, gpointer user_data);

typedef struct PluginInfo PluginInfo;

typedef struct PluginCallback PluginCallback;

typedef struct GeanyData GeanyData;

typedef struct GeanyPluginFuncs GeanyPluginFuncs;

typedef struct GeanyProxyFuncs GeanyProxyFuncs;

typedef struct GeanyPlugin GeanyPlugin;

typedef struct GeanyFunctionsUndefined GeanyFunctions;

typedef struct GeanyKeyGroupInfo GeanyKeyGroupInfo;

typedef struct PluginFields PluginFields;

typedef struct GeanyPrefs GeanyPrefs;

typedef struct GeanyToolPrefs GeanyToolPrefs;

typedef struct PrintingPrefs PrintingPrefs;

typedef struct GeanyProject GeanyProject;

typedef struct GeanySearchPrefs GeanySearchPrefs;

typedef struct GeanyMatchInfo GeanyMatchInfo;

typedef struct SidebarTreeviews SidebarTreeviews;

typedef void(* SpawnReadFunc) (GString *string, GIOCondition condition, gpointer data);

typedef struct _SpawnWriteData SpawnWriteData;

typedef struct StashGroup StashGroup;

typedef gconstpointer StashWidgetID;

typedef struct GeanyTemplatePrefs GeanyTemplatePrefs;

typedef gint TMParserType;

typedef struct TMSourceFile TMSourceFile;

typedef struct TMTag TMTag;

typedef struct TMWorkspace TMWorkspace;

typedef struct GeanyToolbarPrefs GeanyToolbarPrefs;

typedef struct GeanyInterfacePrefs GeanyInterfacePrefs;

typedef struct GeanyMainWidgets GeanyMainWidgets;



/**
 * _GeanyObject: 
 * @parent:  
 *
 * 
 * Instance structure for GeanyObject. 
 * 
 *     
 *
 * 
 *
 */
struct _GeanyObject {
	/*< private >*/
	GObject parent;
};




/**
 * _GeanyObjectClass: 
 * @parent_class:  
 *
 * 
 * Class structure for @GeanyObject. 
 * 
 *     
 *
 * 
 *
 */
struct _GeanyObjectClass {
	/*< private >*/
	GObjectClass parent_class;
};




/**
 * _SpawnWriteData: 
 * @ptr:  Pointer to the data.
 * @size:  Size of the data.
 *
 * 
 * A simple structure used by spawn_write_data() to write data to a channel. 
 * 
 *     
 *
 * 
 *
 */
struct _SpawnWriteData {
	/*< public >*/
	const gchar* ptr;
	/*< public >*/
	gsize size;
};




/**
 * GeanyApp: 
 * @debug_mode:  %TRUE if debug messages should be printed.
 * @configdir:  User configuration directory, usually ~/.config/geany.
 * @datadir:  
 * @docdir:  
 * @tm_workspace:  TagManager workspace/session tags.
 * @project:  Currently active project or %NULL if none is open.
 *
 * 
 * Important application fields. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyApp {
	/*< public >*/
	gboolean debug_mode;
	/*< public >*/
	gchar* configdir;
	/*< private >*/
	gchar* datadir;
	/*< private >*/
	gchar* docdir;
	/*< public >*/
	const TMWorkspace* tm_workspace;
	/*< public >*/
	GeanyProject* project;
};




/**
 * GeanyData: 
 * @app:  Geany application data fields.
 * @main_widgets:  Important widgets in the main window.
 * @documents_array: (element-type GeanyDocument):  Dynamic array of GeanyDocument pointers.
 * @filetypes_array: (element-type GeanyFiletype):  Dynamic array of filetype pointers.
 * @prefs:  General settings.
 * @interface_prefs:  Interface settings.
 * @toolbar_prefs:  Toolbar settings.
 * @editor_prefs:  Editor settings.
 * @file_prefs:  File-related settings.
 * @search_prefs:  Search-related settings.
 * @tool_prefs:  Tool settings.
 * @template_prefs:  Template settings.
 * @_compat:  
 * @filetypes_by_title: (element-type GeanyFiletype):  List of filetype pointers sorted by name, but with filetypes_index(GEANY_FILETYPES_NONE) first, as this is usually treated specially.
 * @object:  Global object signalling events via signals.
 *
 * 
 * This contains pointers to global variables owned by Geany for plugins to use. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyData {
	/*< public >*/
	GeanyApp* app;
	/*< public >*/
	GeanyMainWidgets* main_widgets;
	/*< public >*/
	GPtrArray* documents_array;
	/*< public >*/
	GPtrArray* filetypes_array;
	/*< public >*/
	GeanyPrefs* prefs;
	/*< public >*/
	GeanyInterfacePrefs* interface_prefs;
	/*< public >*/
	GeanyToolbarPrefs* toolbar_prefs;
	/*< public >*/
	GeanyEditorPrefs* editor_prefs;
	/*< public >*/
	GeanyFilePrefs* file_prefs;
	/*< public >*/
	GeanySearchPrefs* search_prefs;
	/*< public >*/
	GeanyToolPrefs* tool_prefs;
	/*< public >*/
	GeanyTemplatePrefs* template_prefs;
	/*< private >*/
	gpointer* _compat;
	/*< public >*/
	GSList* filetypes_by_title;
	/*< public >*/
	GObject* object;
};




/**
 * GeanyDocument: 
 * @is_valid:  Flag used to check if this document is valid when iterating GeanyData::documents_array.
 * @index:  Index in the documents array.
 * @has_tags:  Whether this document supports source code symbols(tags) to show in the sidebar.
 * @file_name:  The UTF-8 encoded file name.
 * @encoding:  The encoding of the document, must be a valid string representation of an encoding, can be retrieved with encodings_get_charset_from_index.
 * @has_bom:  Internally used flag to indicate whether the file of this document has a byte-order-mark.
 * @editor:  The editor associated with the document.
 * @file_type:  The filetype for this document, it's only a reference to one of the elements of the global filetypes array.
 * @tm_file:  TMSourceFile object for this document, or %NULL.
 * @readonly:  Whether this document is read-only.
 * @changed:  Whether this document has been changed since it was last saved.
 * @real_path:  The link-dereferenced, locale-encoded file name.
 * @id:  A pseudo-unique ID for this document.
 * @priv:  
 *
 * 
 * Structure for representing an open tab with all its properties. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyDocument {
	/*< public >*/
	gboolean is_valid;
	/*< public >*/
	gint index;
	/*< public >*/
	gboolean has_tags;
	/*< public >*/
	gchar* file_name;
	/*< public >*/
	gchar* encoding;
	/*< public >*/
	gboolean has_bom;
	/*< public >*/
	GeanyEditor* editor;
	/*< public >*/
	GeanyFiletype* file_type;
	/*< public >*/
	TMSourceFile* tm_file;
	/*< public >*/
	gboolean readonly;
	/*< public >*/
	gboolean changed;
	/*< public >*/
	gchar* real_path;
	/*< public >*/
	guint id;
	/*< private >*/
	struct GeanyDocumentPrivate* priv;
};




/**
 * GeanyEditor: 
 * @document:  The document associated with the editor.
 * @sci:  The Scintilla editor GtkWidget.
 * @line_wrapping:  %TRUE if line wrapping is enabled.
 * @auto_indent:  %TRUE if auto-indentation is enabled.
 * @scroll_percent:  Percentage to scroll view by on paint, if positive.
 * @indent_type:  
 * @line_breaking:  Whether to split long lines as you type.
 * @indent_width:  
 *
 * 
 * Editor-owned fields for each document. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyEditor {
	/*< public >*/
	GeanyDocument* document;
	/*< public >*/
	ScintillaObject* sci;
	/*< public >*/
	gboolean line_wrapping;
	/*< public >*/
	gboolean auto_indent;
	/*< public >*/
	gfloat scroll_percent;
	/*< private >*/
	GeanyIndentType indent_type;
	/*< public >*/
	gboolean line_breaking;
	/*< private >*/
	gint indent_width;
};




/**
 * GeanyEditorPrefs: 
 * @indentation:  
 * @show_white_space:  
 * @show_indent_guide:  
 * @show_line_endings:  
 * @long_line_type:  
 * @long_line_column:  
 * @long_line_color:  
 * @show_markers_margin:  
 * @show_linenumber_margin:  
 * @show_scrollbars:  
 * @scroll_stop_at_last_line:  
 * @line_wrapping:  
 * @use_indicators:  
 * @folding:  
 * @unfold_all_children:  
 * @disable_dnd:  
 * @use_tab_to_indent:  
 * @smart_home_key:  
 * @newline_strip:  
 * @auto_complete_symbols:  
 * @auto_close_xml_tags:  
 * @complete_snippets:  
 * @symbolcompletion_min_chars:  
 * @symbolcompletion_max_height:  
 * @brace_match_ltgt:  
 * @use_gtk_word_boundaries:  
 * @complete_snippets_whilst_editing:  
 * @line_break_column:  
 * @auto_continue_multiline:  
 * @comment_toggle_mark:  
 * @autocompletion_max_entries:  
 * @autoclose_chars:  
 * @autocomplete_doc_words:  
 * @completion_drops_rest_of_word:  
 * @color_scheme:  
 * @show_virtual_space:  
 * @long_line_enabled:  
 * @autocompletion_update_freq:  
 * @scroll_lines_around_cursor:  
 * @ime_interaction:  
 *
 * 
 * Default prefs when creating a new editor window. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyEditorPrefs {
	/*< private >*/
	GeanyIndentPrefs* indentation;
	/*< private >*/
	gboolean show_white_space;
	/*< private >*/
	gboolean show_indent_guide;
	/*< private >*/
	gboolean show_line_endings;
	/*< private >*/
	gint long_line_type;
	/*< private >*/
	gint long_line_column;
	/*< private >*/
	gchar* long_line_color;
	/*< private >*/
	gboolean show_markers_margin;
	/*< private >*/
	gboolean show_linenumber_margin;
	/*< private >*/
	gboolean show_scrollbars;
	/*< private >*/
	gboolean scroll_stop_at_last_line;
	/*< private >*/
	gboolean line_wrapping;
	/*< private >*/
	gboolean use_indicators;
	/*< private >*/
	gboolean folding;
	/*< private >*/
	gboolean unfold_all_children;
	/*< private >*/
	gboolean disable_dnd;
	/*< private >*/
	gboolean use_tab_to_indent;
	/*< private >*/
	gboolean smart_home_key;
	/*< private >*/
	gboolean newline_strip;
	/*< private >*/
	gboolean auto_complete_symbols;
	/*< private >*/
	gboolean auto_close_xml_tags;
	/*< private >*/
	gboolean complete_snippets;
	/*< private >*/
	gint symbolcompletion_min_chars;
	/*< private >*/
	gint symbolcompletion_max_height;
	/*< private >*/
	gboolean brace_match_ltgt;
	/*< private >*/
	gboolean use_gtk_word_boundaries;
	/*< private >*/
	gboolean complete_snippets_whilst_editing;
	/*< private >*/
	gint line_break_column;
	/*< private >*/
	gboolean auto_continue_multiline;
	/*< private >*/
	gchar* comment_toggle_mark;
	/*< private >*/
	guint autocompletion_max_entries;
	/*< private >*/
	guint autoclose_chars;
	/*< private >*/
	gboolean autocomplete_doc_words;
	/*< private >*/
	gboolean completion_drops_rest_of_word;
	/*< private >*/
	gchar* color_scheme;
	/*< private >*/
	gint show_virtual_space;
	/*< private >*/
	gboolean long_line_enabled;
	/*< private >*/
	gint autocompletion_update_freq;
	/*< private >*/
	gint scroll_lines_around_cursor;
	/*< private >*/
	gint ime_interaction;
};




/**
 * GeanyFilePrefs: 
 * @default_new_encoding:  
 * @default_open_encoding:  
 * @final_new_line:  
 * @strip_trailing_spaces:  
 * @replace_tabs:  
 * @tab_order_ltr:  
 * @tab_order_beside:  
 * @show_tab_cross:  
 * @mru_length:  
 * @default_eol_character:  
 * @disk_check_timeout:  
 * @cmdline_new_files:  
 * @use_safe_file_saving:  
 * @ensure_convert_new_lines:  
 * @gio_unsafe_save_backup:  
 * @use_gio_unsafe_file_saving:  
 * @extract_filetype_regex:  
 * @tab_close_switch_to_mru:  
 * @keep_edit_history_on_reload:  
 * @show_keep_edit_history_on_reload_msg:  
 * @reload_clean_doc_on_file_change:  
 *
 * 
 * File Prefs. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyFilePrefs {
	/*< private >*/
	gint default_new_encoding;
	/*< private >*/
	gint default_open_encoding;
	/*< private >*/
	gboolean final_new_line;
	/*< private >*/
	gboolean strip_trailing_spaces;
	/*< private >*/
	gboolean replace_tabs;
	/*< private >*/
	gboolean tab_order_ltr;
	/*< private >*/
	gboolean tab_order_beside;
	/*< private >*/
	gboolean show_tab_cross;
	/*< private >*/
	guint mru_length;
	/*< private >*/
	gint default_eol_character;
	/*< private >*/
	gint disk_check_timeout;
	/*< private >*/
	gboolean cmdline_new_files;
	/*< private >*/
	gboolean use_safe_file_saving;
	/*< private >*/
	gboolean ensure_convert_new_lines;
	/*< private >*/
	gboolean gio_unsafe_save_backup;
	/*< private >*/
	gboolean use_gio_unsafe_file_saving;
	/*< private >*/
	gchar* extract_filetype_regex;
	/*< private >*/
	gboolean tab_close_switch_to_mru;
	/*< private >*/
	gboolean keep_edit_history_on_reload;
	/*< private >*/
	gboolean show_keep_edit_history_on_reload_msg;
	/*< private >*/
	gboolean reload_clean_doc_on_file_change;
};




/**
 * GeanyFiletype: 
 * @id:  Index in filetypes.
 * @lang:  
 * @name:  Untranslated short name, such as "C", "None".
 * @title:  Shown in the file open dialog, such as "C source file".
 * @extension:  Default file extension for new files, or %NULL.
 * @pattern:  Array of filename-matching wildcard strings.
 * @context_action_cmd:  
 * @comment_open:  
 * @comment_close:  
 * @comment_use_indent:  
 * @group:  
 * @error_regex_string:  
 * @lexer_filetype:  
 * @mime_type:  
 * @icon:  
 * @comment_single:  
 * @indent_type:  
 * @indent_width:  
 * @priv:  
 *
 * 
 * Represents a filetype. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyFiletype {
	/*< public >*/
	GeanyFiletypeID id;
	/*< private >*/
	TMParserType lang;
	/*< public >*/
	gchar* name;
	/*< public >*/
	gchar* title;
	/*< public >*/
	gchar* extension;
	/*< public >*/
	gchar** pattern;
	/*< private >*/
	gchar* context_action_cmd;
	/*< private >*/
	gchar* comment_open;
	/*< private >*/
	gchar* comment_close;
	/*< private >*/
	gboolean comment_use_indent;
	/*< private >*/
	GeanyFiletypeGroupID group;
	/*< private >*/
	gchar* error_regex_string;
	/*< private >*/
	GeanyFiletype* lexer_filetype;
	/*< private >*/
	gchar* mime_type;
	/*< private >*/
	GIcon* icon;
	/*< private >*/
	gchar* comment_single;
	/*< private >*/
	gint indent_type;
	/*< private >*/
	gint indent_width;
	/*< private >*/
	struct GeanyFiletypePrivate* priv;
};




/**
 * GeanyIndentPrefs: 
 * @width:  Indent width.
 * @type:  Whether to use tabs, spaces or both to indent.
 * @hard_tab_width:  Width of a tab, but only when using GEANY_INDENT_TYPE_BOTH.
 * @auto_indent_mode:  
 * @detect_type:  
 * @detect_width:  
 *
 * 
 * Indentation prefs that might be different according to project or filetype. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyIndentPrefs {
	/*< public >*/
	gint width;
	/*< public >*/
	GeanyIndentType type;
	/*< public >*/
	gint hard_tab_width;
	/*< private >*/
	GeanyAutoIndent auto_indent_mode;
	/*< private >*/
	gboolean detect_type;
	/*< private >*/
	gboolean detect_width;
};




/**
 * GeanyInterfacePrefs: 
 * @sidebar_symbol_visible:  whether the symbol sidebar is visible
 * @sidebar_openfiles_visible:  whether the open file list is visible
 * @editor_font:  editor font
 * @tagbar_font:  symbol sidebar font
 * @msgwin_font:  message window font
 * @show_notebook_tabs:  whether editor tabs are visible
 * @tab_pos_editor:  positions of editor's tabs
 * @tab_pos_msgwin:  positions of message window's tabs
 * @tab_pos_sidebar:  positions of sidebar's tabs
 * @statusbar_visible:  whether the status bar is visible
 * @show_symbol_list_expanders:  whether to show expanders in the symbol list
 * @notebook_double_click_hides_widgets:  whether a double click on notebook tabs hides all other windows
 * @highlighting_invert_all:  whether highlighting colors are inverted
 * @sidebar_pos:  position of the sidebar (left or right)
 * @msgwin_status_visible:  whether message window's status tab is visible
 * @msgwin_compiler_visible:  whether message window's compiler tab is visible
 * @msgwin_messages_visible:  whether message window's messages tab is visible
 * @msgwin_scribble_visible:  whether message window's scribble tab is visible
 * @use_native_windows_dialogs:  whether to use native Windows' dialogs (only used on Windows)
 * @compiler_tab_autoscroll:  whether compiler messages window is automatically scrolled to show new messages
 * @msgwin_orientation:  orientation of the message window
 * @symbols_sort_mode:  symbol list sorting mode
 *
 * 
 * Interface preferences. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyInterfacePrefs {
	/*< public >*/
	gboolean sidebar_symbol_visible;
	/*< public >*/
	gboolean sidebar_openfiles_visible;
	/*< public >*/
	gchar* editor_font;
	/*< public >*/
	gchar* tagbar_font;
	/*< public >*/
	gchar* msgwin_font;
	/*< public >*/
	gboolean show_notebook_tabs;
	/*< public >*/
	gint tab_pos_editor;
	/*< public >*/
	gint tab_pos_msgwin;
	/*< public >*/
	gint tab_pos_sidebar;
	/*< public >*/
	gboolean statusbar_visible;
	/*< public >*/
	gboolean show_symbol_list_expanders;
	/*< public >*/
	gboolean notebook_double_click_hides_widgets;
	/*< public >*/
	gboolean highlighting_invert_all;
	/*< public >*/
	gint sidebar_pos;
	/*< public >*/
	gboolean msgwin_status_visible;
	/*< public >*/
	gboolean msgwin_compiler_visible;
	/*< public >*/
	gboolean msgwin_messages_visible;
	/*< public >*/
	gboolean msgwin_scribble_visible;
	/*< public >*/
	gboolean use_native_windows_dialogs;
	/*< public >*/
	gboolean compiler_tab_autoscroll;
	/*< public >*/
	gint msgwin_orientation;
	/*< public >*/
	gint symbols_sort_mode;
};




/**
 * GeanyKeyBinding: 
 * @key:  Key value in lower-case, such as GDK_a or 0.
 * @mods:  Modifier keys, such as GDK_CONTROL_MASK or 0.
 * @name:  Key name for the configuration file, such as "menu_new".
 * @label:  Label used in the preferences dialog keybindings tab.
 * @callback:  Function called when the key combination is pressed, or %NULL to use the group callback (preferred).
 * @menu_item:  Optional widget to set an accelerator for, or %NULL.
 * @id:  
 * @default_key:  
 * @default_mods:  
 * @cb_func:  
 * @cb_data:  
 * @cb_data_destroy:  
 *
 * 
 * Represents a single keybinding action. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyKeyBinding {
	/*< public >*/
	guint key;
	/*< public >*/
	GdkModifierType mods;
	/*< public >*/
	gchar* name;
	/*< public >*/
	gchar* label;
	/*< public >*/
	GeanyKeyCallback callback;
	/*< public >*/
	GtkWidget* menu_item;
	/*< private >*/
	guint id;
	/*< private >*/
	guint default_key;
	/*< private >*/
	GdkModifierType default_mods;
	/*< private >*/
	GeanyKeyBindingFunc cb_func;
	/*< private >*/
	gpointer cb_data;
	/*< private >*/
	GDestroyNotify cb_data_destroy;
};




/**
 * GeanyLexerStyle: 
 * @foreground:  Foreground text colour, in 0xBBGGRR format.
 * @background:  Background text colour, in 0xBBGGRR format.
 * @bold:  Bold.
 * @italic:  Italic.
 *
 * 
 * Fields representing the different attributes of a Scintilla lexer style. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyLexerStyle {
	/*< public >*/
	gint foreground;
	/*< public >*/
	gint background;
	/*< public >*/
	gboolean bold;
	/*< public >*/
	gboolean italic;
};




/**
 * GeanyMainWidgets: 
 * @window:  Main window.
 * @toolbar:  Main toolbar.
 * @sidebar_notebook:  Sidebar notebook.
 * @notebook:  Document notebook.
 * @editor_menu:  Popup editor menu.
 * @tools_menu:  Most plugins add menu items to the Tools menu.
 * @progressbar:  Progress bar widget in the status bar to show progress of various actions.
 * @message_window_notebook:  Message Window notebook.
 * @project_menu:  Plugins modifying the project can add their items to the Project menu.
 *
 * 
 * Important widgets in the main window. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyMainWidgets {
	/*< public >*/
	GtkWidget* window;
	/*< public >*/
	GtkWidget* toolbar;
	/*< public >*/
	GtkWidget* sidebar_notebook;
	/*< public >*/
	GtkWidget* notebook;
	/*< public >*/
	GtkWidget* editor_menu;
	/*< public >*/
	GtkWidget* tools_menu;
	/*< public >*/
	GtkWidget* progressbar;
	/*< public >*/
	GtkWidget* message_window_notebook;
	/*< public >*/
	GtkWidget* project_menu;
};




/**
 * GeanyPlugin: 
 * @info:  Fields set in plugin_set_info().
 * @geany_data:  Pointer to global GeanyData intance.
 * @funcs:  Functions implemented by the plugin, set in geany_load_module()
 * @proxy_funcs:  Hooks implemented by the plugin if it wants to act as a proxy Must be set prior to calling geany_plugin_register_proxy()
 * @priv:  
 *
 * 
 * Basic information for the plugin and identification. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyPlugin {
	/*< public >*/
	PluginInfo* info;
	/*< public >*/
	GeanyData* geany_data;
	/*< public >*/
	GeanyPluginFuncs* funcs;
	/*< public >*/
	GeanyProxyFuncs* proxy_funcs;
	/*< private >*/
	struct GeanyPluginPrivate* priv;
};




/**
 * GeanyPluginFuncs: 
 * @callbacks:  Array of plugin-provided signal handlers.
 * @init:  Called to initialize the plugin, when the user activates it (must not be %NULL)
 * @configure:  plugins configure dialog, optional (can be %NULL)
 * @help:  Called when the plugin should show some help, optional (can be %NULL)
 * @cleanup:  Called when the plugin is disabled or when Geany exits (must not be %NULL)
 *
 * 
 * Callback functions that need to be implemented for every plugin. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyPluginFuncs {
	/*< public >*/
	PluginCallback* callbacks;
	/*< public >*/
	gboolean(* init) (GeanyPlugin *plugin, gpointer pdata);
	/*< public >*/
	GtkWidget*(* configure) (GeanyPlugin *plugin, GtkDialog *dialog, gpointer pdata);
	/*< public >*/
	void(* help) (GeanyPlugin *plugin, gpointer pdata);
	/*< public >*/
	void(* cleanup) (GeanyPlugin *plugin, gpointer pdata);
};




/**
 * GeanyPrefs: 
 * @load_session:  
 * @load_plugins:  
 * @save_winpos:  
 * @confirm_exit:  
 * @beep_on_errors:  
 * @suppress_status_messages:  
 * @switch_to_status:  
 * @auto_focus:  
 * @default_open_path:  Default path to look for files when no other path is appropriate.
 * @custom_plugin_path:  
 * @save_wingeom:  
 *
 * 
 * General Preferences dialog settings. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyPrefs {
	/*< private >*/
	gboolean load_session;
	/*< private >*/
	gboolean load_plugins;
	/*< private >*/
	gboolean save_winpos;
	/*< private >*/
	gboolean confirm_exit;
	/*< private >*/
	gboolean beep_on_errors;
	/*< private >*/
	gboolean suppress_status_messages;
	/*< private >*/
	gboolean switch_to_status;
	/*< private >*/
	gboolean auto_focus;
	/*< public >*/
	gchar* default_open_path;
	/*< private >*/
	gchar* custom_plugin_path;
	/*< private >*/
	gboolean save_wingeom;
};




/**
 * GeanyProject: 
 * @name:  The name of the project.
 * @description:  Short description of the project.
 * @file_name:  Where the project file is stored (in UTF-8).
 * @base_path:  Base path of the project directory (in UTF-8, maybe relative).
 * @type:  Identifier whether it is a pure Geany project or modified/extended by a plugin.
 * @file_patterns:  Array of filename extension patterns.
 * @priv:  
 *
 * 
 * Structure for representing a project. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyProject {
	/*< public >*/
	gchar* name;
	/*< public >*/
	gchar* description;
	/*< public >*/
	gchar* file_name;
	/*< public >*/
	gchar* base_path;
	/*< public >*/
	gint type;
	/*< public >*/
	GStrv file_patterns;
	/*< private >*/
	struct GeanyProjectPrivate* priv;
};




/**
 * GeanyProxyFuncs: 
 * @probe:  Called to determine whether the proxy is truly responsible for the requested plugin.
 * @load:  Called after probe(), to perform the actual job of loading the plugin.
 * @unload:  Called when the user initiates unloading of a plugin, e.g.
 *
 * 
 * Hooks that need to be implemented by every proxy. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyProxyFuncs {
	/*< public >*/
	gint(* probe) (GeanyPlugin *proxy, const gchar *filename, gpointer pdata);
	/*< public >*/
	gpointer(* load) (GeanyPlugin *proxy, GeanyPlugin *subplugin, const gchar *filename, gpointer pdata);
	/*< public >*/
	void(* unload) (GeanyPlugin *proxy, GeanyPlugin *subplugin, gpointer load_data, gpointer pdata);
};




/**
 * GeanySearchPrefs: 
 * @always_wrap:  
 * @use_current_word:  Use current word for default search text.
 * @use_current_file_dir:  
 * @hide_find_dialog:  
 * @replace_and_find_by_default:  
 * @find_selection_type:  
 *
 * 
 * Search preferences. 
 * 
 *     
 *
 * 
 *
 */
struct GeanySearchPrefs {
	/*< private >*/
	gboolean always_wrap;
	/*< public >*/
	gboolean use_current_word;
	/*< private >*/
	gboolean use_current_file_dir;
	/*< private >*/
	gboolean hide_find_dialog;
	/*< private >*/
	gboolean replace_and_find_by_default;
	/*< private >*/
	GeanyFindSelOptions find_selection_type;
};




/**
 * GeanyTemplatePrefs: 
 * @developer:  Name.
 * @company:  Company.
 * @mail:  Email.
 * @initials:  Initials.
 * @version:  Initial version.
 * @year_format:  
 * @date_format:  
 * @datetime_format:  
 *
 * 
 * Template preferences. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyTemplatePrefs {
	/*< public >*/
	gchar* developer;
	/*< public >*/
	gchar* company;
	/*< public >*/
	gchar* mail;
	/*< public >*/
	gchar* initials;
	/*< public >*/
	gchar* version;
	/*< private >*/
	gchar* year_format;
	/*< private >*/
	gchar* date_format;
	/*< private >*/
	gchar* datetime_format;
};




/**
 * GeanyToolbarPrefs: 
 * @visible:  
 * @icon_size:  
 * @icon_style:  Icon style.
 * @use_gtk_default_style:  
 * @use_gtk_default_icon:  
 * @append_to_menu:  
 *
 * 
 * Toolbar settings. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyToolbarPrefs {
	/*< private >*/
	gboolean visible;
	/*< private >*/
	GtkIconSize icon_size;
	/*< public >*/
	GtkToolbarStyle icon_style;
	/*< private >*/
	gboolean use_gtk_default_style;
	/*< private >*/
	gboolean use_gtk_default_icon;
	/*< private >*/
	gboolean append_to_menu;
};




/**
 * GeanyToolPrefs: 
 * @browser_cmd:  web browser command
 * @term_cmd:  terminal emulator command
 * @grep_cmd:  grep command
 * @context_action_cmd:  context action command
 *
 * 
 * Tools preferences. 
 * 
 *     
 *
 * 
 *
 */
struct GeanyToolPrefs {
	/*< public >*/
	gchar* browser_cmd;
	/*< public >*/
	gchar* term_cmd;
	/*< public >*/
	gchar* grep_cmd;
	/*< public >*/
	gchar* context_action_cmd;
};




/**
 * PluginCallback: 
 * @signal_name:  The name of signal, must be an existing signal.
 * @callback:  A callback function which is called when the signal is emitted.
 * @after:  Set to TRUE to connect your handler with g_signal_connect_after().
 * @user_data:  The user data passed to the signal handler.
 *
 * 
 * Callback array entry type used with the plugin_callbacks symbol. 
 * 
 *     
 *
 * 
 *
 */
struct PluginCallback {
	/*< public >*/
	const gchar* signal_name;
	/*< public >*/
	GCallback callback;
	/*< public >*/
	gboolean after;
	/*< public >*/
	gpointer user_data;
};




/**
 * PluginInfo: 
 * @name:  The name of the plugin.
 * @description:  The description of the plugin.
 * @version:  The version of the plugin.
 * @author:  The author of the plugin.
 *
 * 
 * Basic information about a plugin available to Geany without loading the plugin. 
 * 
 *     
 *
 * 
 *
 */
struct PluginInfo {
	/*< public >*/
	const gchar* name;
	/*< public >*/
	const gchar* description;
	/*< public >*/
	const gchar* version;
	/*< public >*/
	const gchar* author;
};




/**
 * TMSourceFile: 
 * @lang:  
 * @file_name:  Full file name (inc.
 * @short_name:  Just the name of the file (without the path)
 * @tags_array: (element-type TMTag):  Sorted tag array obtained by parsing the object.
 *
 * 
 * The TMSourceFile structure represents the source file and its tags in the tag manager. 
 * 
 *     
 *
 * 
 *
 */
struct TMSourceFile {
	/*< private >*/
	TMParserType lang;
	/*< public >*/
	char* file_name;
	/*< public >*/
	char* short_name;
	/*< public >*/
	GPtrArray* tags_array;
};




/**
 * TMTag: 
 * @name:  Name of tag.
 * @type:  Tag Type.
 * @refcount:  
 * @file:  These are tag attributes.
 * @line:  Line number of the tag.
 * @local:  Is the tag of local scope.
 * @pointerOrder:  
 * @arglist:  Argument list (functions/prototypes/macros)
 * @scope:  Scope of tag.
 * @inheritance:  Parent classes.
 * @var_type:  Variable type (maps to struct for typedefs)
 * @access:  Access type (public/protected/private/etc.)
 * @impl:  Implementation (e.g.
 * @lang:  
 *
 * 
 * The TMTag structure represents a single tag in the tag manager. 
 * 
 *     
 *
 * 
 *
 */
struct TMTag {
	/*< public >*/
	char* name;
	/*< public >*/
	TMTagType type;
	/*< private >*/
	gint refcount;
	/*< public >*/
	TMSourceFile* file;
	/*< public >*/
	gulong line;
	/*< public >*/
	gboolean local;
	/*< private >*/
	guint pointerOrder;
	/*< public >*/
	char* arglist;
	/*< public >*/
	char* scope;
	/*< public >*/
	char* inheritance;
	/*< public >*/
	char* var_type;
	/*< public >*/
	char access;
	/*< public >*/
	char impl;
	/*< private >*/
	TMParserType lang;
};




/**
 * TMWorkspace: 
 * @global_tags: (element-type TMTag):  Global tags loaded at startup.
 * @source_files: (element-type TMSourceFile):  An array of TMSourceFile pointers.
 * @tags_array: (element-type TMTag):  Sorted tags from all source files (just pointers to source file tags, the tag objects are owned by the source files).
 * @typename_array:  
 * @global_typename_array:  
 *
 * 
 * The Tag Manager Workspace. 
 * 
 *     
 *
 * 
 *
 */
struct TMWorkspace {
	/*< public >*/
	GPtrArray* global_tags;
	/*< public >*/
	GPtrArray* source_files;
	/*< public >*/
	GPtrArray* tags_array;
	/*< private >*/
	GPtrArray* typename_array;
	/*< private >*/
	GPtrArray* global_typename_array;
};




/**
 * build_remove_menu_item: 
 * @src:  the source of the menu item to remove.
 * @grp:  the group of the command to remove.
 * @cmd:  the index (from 0) of the command within the group. A negative value will remove the whole group.
 *
 * 
 * Remove the specified Build menu item. 
 * 
 *         
 *
 * 
 * Makes the specified menu item configuration no longer exist. This is different to setting fields to blank because the menu item will be deleted from the configuration file on saving (except the system filetypes settings See Build Menu Configuration section of the Manual).
 * 
 * 
 * 
 * 
 * If any parameter is out of range does nothing.
 * 
 * Updates the menu. 
 * 
 *         
 *
 */
void build_remove_menu_item (const GeanyBuildSource src, const GeanyBuildGroup grp, const gint cmd);



/**
 * build_get_current_menu_item: 
 * @grp:  the group of the specified menu item.
 * @cmd:  the index of the command within the group.
 * @fld:  the field to return
 *
 * 
 * Get the string for the menu item field. 
 * 
 *         
 *
 * 
 * Get the current highest priority command specified by @grp and @cmd. This is the one that the menu item will use if activated.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  a pointer to the constant string or %NULL if it doesn't exist. This is a pointer to an internal structure and must not be freed.
 */
const gchar* build_get_current_menu_item (const GeanyBuildGroup grp, const guint cmd, const GeanyBuildCmdEntries fld);



/**
 * build_set_menu_item: 
 * @src:  the source of the menu item
 * @grp:  the group of the specified menu item.
 * @cmd:  the index of the menu item within the group.
 * @fld:  the field in the menu item command to set
 * @val:  the value to set the field to, is copied
 *
 * 
 * Set the string for the menu item field. 
 * 
 *         
 *
 * 
 * Set the specified field of the command specified by @src, @grp and @cmd.
 * 
 * 
 * 
 * 
 *         
 *
 */
void build_set_menu_item (const GeanyBuildSource src, const GeanyBuildGroup grp, const guint cmd, const GeanyBuildCmdEntries fld, const gchar *val);



/**
 * build_activate_menu_item: 
 * @grp:  the group of the specified menu item.
 * @cmd:  the index of the command within the group.
 *
 * 
 * Activate the menu item. 
 * 
 *         
 *
 * 
 * Activate the menu item specified by @grp and @cmd.
 * 
 * 
 * 
 * 
 *         
 *
 */
void build_activate_menu_item (const GeanyBuildGroup grp, const guint cmd);



/**
 * build_get_group_count: 
 * @grp:  the group of the specified menu item.
 *
 * 
 * Get the count of commands for the group. 
 * 
 *         
 *
 * 
 * Get the number of commands in the group specified by @grp.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  a count of the number of commands in the group
 */
guint build_get_group_count (const GeanyBuildGroup grp);



/**
 * dialogs_show_save_as: 
 *
 * 
 * Shows the Save As dialog for the current notebook page. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the file was saved, otherwise %FALSE.
 */
gboolean dialogs_show_save_as (void);



/**
 * dialogs_show_msgbox: 
 * @type:  A GtkMessageType, e.g. GTK_MESSAGE_INFO, GTK_MESSAGE_WARNING, GTK_MESSAGE_QUESTION, GTK_MESSAGE_ERROR.
 * @text:  Printf()-style format string.
 * @...:  Arguments for the @text format string.
 *
 * 
 * Shows a message box of the type @type with @text. 
 * 
 *         
 *
 * 
 * On Unix-like systems a GTK message dialog box is shown, on Win32 systems a native Windows message dialog box is shown.
 * 
 * 
 * 
 * 
 *         
 *
 */
void dialogs_show_msgbox (GtkMessageType type, const gchar *text,...);



/**
 * dialogs_show_input: 
 * @title:  Dialog title.
 * @parent: (nullable):  The currently focused window, usually geany->main_widgets->window. %NULL can be used but is discouraged due to window manager effects.
 * @label_text: (nullable):  Label text, or %NULL.
 * @default_text: (nullable):  Text to display in the input field, or %NULL.
 *
 * 
 * Asks the user for text input. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  New copy of user input or %NULL if cancelled.
 *
 * Since: 0.20.
 */
gchar* dialogs_show_input (const gchar *title, GtkWindow *parent, const gchar *label_text, const gchar *default_text);



/**
 * dialogs_show_input_numeric: 
 * @title:  The dialog title.
 * @label_text:  The shown dialog label.
 * @value:  The default value for the spin button and the return location of the entered value. Must be non-NULL.
 * @min:  Minimum allowable value (see documentation for gtk_spin_button_new_with_range()).
 * @max:  Maximum allowable value (see documentation for gtk_spin_button_new_with_range()).
 * @step:  Increment added or subtracted by spinning the widget (see documentation for gtk_spin_button_new_with_range()).
 *
 * 
 * Shows an input box to enter a numerical value using a GtkSpinButton. 
 * 
 *         
 *
 * 
 * If the dialog is aborted, @value remains untouched.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if a value was entered and the dialog closed with 'OK'. %FALSE otherwise.
 *
 * Since: 0.16
 */
gboolean dialogs_show_input_numeric (const gchar *title, const gchar *label_text, gdouble *value, gdouble min, gdouble max, gdouble step);



/**
 * dialogs_show_question: 
 * @text:  Printf()-style format string.
 * @...:  Arguments for the @text format string.
 *
 * 
 * Shows a question message box with @text and Yes/No buttons. 
 * 
 *         
 *
 * 
 * On Unix-like systems a GTK message dialog box is shown, on Win32 systems a native Windows message dialog box is shown.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the user answered with Yes, otherwise %FALSE.
 */
gboolean dialogs_show_question (const gchar *text,...);



/**
 * document_find_by_real_path: 
 * @realname:  The filename to search, which should be identical to the string returned by utils_get_real_path().
 *
 * 
 * Finds a document whose real_path field matches the given filename. 
 * 
 *         
 *
 * 
 * 
 * 
 * This is only really useful when passing a TMSourceFile::file_name. 
 * 
 * 
 * 
 * See GeanyDocument::real_path. 
 * 
 * 
 * 
 * See document_find_by_filename().
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  The matching document, or %NULL.
 *
 * Since: 0.15
 */
GeanyDocument* document_find_by_real_path (const gchar *realname);



/**
 * document_find_by_filename: 
 * @utf8_filename:  The filename to search (in UTF-8 encoding).
 *
 * 
 * Finds a document with the given filename. 
 * 
 *         
 *
 * 
 * This matches either an exact GeanyDocument::file_name string, or variant filenames with relative elements in the path (e.g. "/dir/..//name" will match "/name").
 * 
 * 
 * 
 * See document_find_by_real_path(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  The matching document, or %NULL.
 */
GeanyDocument* document_find_by_filename (const gchar *utf8_filename);



/**
 * document_find_by_id: 
 * @id:  The ID of the document to find
 *
 * 
 * Lookup an old document by its ID. 
 * 
 *         
 *
 * 
 * Useful when the corresponding document may have been closed since the ID was retrieved. 
 * 
 * Example: 
 * |[<!-- language="C" -->
 *   static guint id;
 *   GeanyDocument *doc = ...;
 *   id = doc->id;   // store ID
 *   ...
 *   // time passes - the document may have been closed by now
 *   GeanyDocument *doc = document_find_by_id(id);
 *   gboolean still_open = (doc != NULL);
 * ]| 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  %NULL if the document is no longer open.
 *
 * Since: 1.25.
 */
GeanyDocument* document_find_by_id (guint id);



/**
 * document_get_notebook_page: 
 * @doc:  The document.
 *
 * 
 * Gets the notebook page index for a document. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The index.
 *
 * Since: 0.19
 */
gint document_get_notebook_page (GeanyDocument *doc);



/**
 * document_get_from_page: 
 * @page_num:  The notebook page number to search.
 *
 * 
 * Finds the document for the given notebook page @page_num. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  The corresponding document for the given notebook page, or %NULL.
 */
GeanyDocument* document_get_from_page (guint page_num);



/**
 * document_get_current: 
 *
 * 
 * Finds the current document. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  A pointer to the current document or %NULL if there are no opened documents.
 */
GeanyDocument* document_get_current (void);



/**
 * document_get_basename_for_display: 
 * @doc:  The document to use.
 * @length:  The length of the resulting string or -1 to use a default value.
 *
 * 
 * Returns the last part of the filename of the given GeanyDocument. 
 * 
 *         
 *
 * 
 * The result is also truncated to a maximum of @length characters in case the filename is very long.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The ellipsized last part of the filename of @doc, should be freed when no longer needed.
 *
 * Since: 0.17
 */
gchar* document_get_basename_for_display (GeanyDocument *doc, gint length);



/**
 * document_set_text_changed: 
 * @doc:  The document to use.
 * @changed:  Whether the document state should indicate changes have been made.
 *
 * 
 * Updates the tab labels, the status bar, the window title and some save-sensitive buttons according to the document's save state. 
 * 
 *         
 *
 * 
 * This is called by Geany mostly when opening or saving files.
 * 
 * 
 * 
 * 
 *         
 *
 */
void document_set_text_changed (GeanyDocument *doc, gboolean changed);



/**
 * document_close: 
 * @doc:  The document to remove.
 *
 * 
 * Closes the given document. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the document was actually removed or %FALSE otherwise.
 *
 * Since: 0.15
 */
gboolean document_close (GeanyDocument *doc);



/**
 * document_remove_page: 
 * @page_num:  The notebook page number to remove.
 *
 * 
 * Removes the given notebook tab at @page_num and clears all related information in the document list. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the document was actually removed or %FALSE otherwise.
 */
gboolean document_remove_page (guint page_num);



/**
 * document_new_file: 
 * @utf8_filename: (nullable):  The file name in UTF-8 encoding, or %NULL to open a file as "untitled".
 * @ft: (nullable):  The filetype to set or %NULL to detect it from @filename if not %NULL.
 * @text: (nullable):  The initial content of the file (in UTF-8 encoding), or %NULL.
 *
 * 
 * Creates a new document. 
 * 
 *         
 *
 * 
 * Line endings in @text will be converted to the default setting. Afterwards, the "document-new" signal is emitted for plugins.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  The new document.
 */
GeanyDocument* document_new_file (const gchar *utf8_filename, GeanyFiletype *ft, const gchar *text);



/**
 * document_open_file: 
 * @locale_filename:  The filename of the document to load, in locale encoding.
 * @readonly:  Whether to open the document in read-only mode.
 * @ft: (nullable):  The filetype for the document or %NULL to auto-detect the filetype.
 * @forced_enc: (nullable):  The file encoding to use or %NULL to auto-detect the file encoding.
 *
 * 
 * Opens a document specified by @locale_filename. 
 * 
 *         
 *
 * 
 * Afterwards, the "document-open" signal is emitted for plugins.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  The document opened or %NULL.
 */
GeanyDocument* document_open_file (const gchar *locale_filename, gboolean readonly, GeanyFiletype *ft, const gchar *forced_enc);



/**
 * document_open_files: 
 * @filenames: (element-type filename):  A list of filenames to load, in locale encoding.
 * @readonly:  Whether to open the document in read-only mode.
 * @ft: (nullable):  The filetype for the document or %NULL to auto-detect the filetype.
 * @forced_enc: (nullable):  The file encoding to use or %NULL to auto-detect the file encoding.
 *
 * 
 * Opens each file in the list @filenames. 
 * 
 *         
 *
 * 
 * Internally, document_open_file() is called for every list item.
 * 
 * 
 * 
 * 
 *         
 *
 */
void document_open_files (const GSList *filenames, gboolean readonly, GeanyFiletype *ft, const gchar *forced_enc);



/**
 * document_reload_force: 
 * @doc:  The document to reload.
 * @forced_enc: (nullable):  The file encoding to use or %NULL to auto-detect the file encoding.
 *
 * 
 * Reloads the document with the specified file encoding. 
 * 
 *         
 *
 * 
 * @forced_enc or %NULL to auto-detect the file encoding.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the document was actually reloaded or %FALSE otherwise.
 */
gboolean document_reload_force (GeanyDocument *doc, const gchar *forced_enc);



/**
 * document_rename_file: 
 * @doc:  The current document which should be renamed.
 * @new_filename:  The new filename in UTF-8 encoding.
 *
 * 
 * Renames the file in @doc to @new_filename. 
 * 
 *         
 *
 * 
 * Only the file on disk is actually renamed, you still have to call document_save_file_as() to change the @doc object. It also stops monitoring for file changes to prevent receiving too many file change events while renaming. File monitoring is setup again in document_save_file_as().
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void document_rename_file (GeanyDocument *doc, const gchar *new_filename);



/**
 * document_save_file_as: 
 * @doc:  The document for the file to save.
 * @utf8_fname: (nullable):  The new name for the document, in UTF-8, or %NULL.
 *
 * 
 * Saves the document, detecting the filetype. 
 * 
 *         
 *
 * 
 * 
 * 
 * See document_save_file().
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the file was saved or %FALSE if the file could not be saved.
 *
 * Since: 0.16
 */
gboolean document_save_file_as (GeanyDocument *doc, const gchar *utf8_fname);



/**
 * document_save_file: 
 * @doc:  The document to save.
 * @force:  Whether to save the file even if it is not modified.
 *
 * 
 * Saves the document. 
 * 
 *         
 *
 * 
 * Also shows the Save As dialog if necessary. If the file is not modified, this function may do nothing unless @force is set to %TRUE.
 * 
 * Saving may include replacing tabs with spaces, stripping trailing spaces and adding a final new line at the end of the file, depending on user preferences. Then the "document-before-save" signal is emitted, allowing plugins to modify the document before it is saved, and data is actually written to disk.
 * 
 * On successful saving:
 * 
 *  - GeanyDocument::real_path is set.
 * 
 *  - The filetype is set again or auto-detected if it wasn't set yet.
 * 
 *  - The "document-save" signal is emitted for plugins.
 * 
 * 
 * 
 * 
 * You should ensure doc->file_name has an absolute path unless you want the Save As dialog to be shown. A %NULL value also shows the dialog. This behaviour was added in Geany 1.22.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the file was saved or %FALSE if the file could not or should not be saved.
 */
gboolean document_save_file (GeanyDocument *doc, gboolean force);



/**
 * document_set_filetype: 
 * @doc:  The document to use.
 * @type:  The filetype.
 *
 * 
 * Sets the filetype of the document (which controls syntax highlighting and tags) 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void document_set_filetype (GeanyDocument *doc, GeanyFiletype *type);



/**
 * document_set_encoding: 
 * @doc:  The document to use.
 * @new_encoding:  The encoding to be set for the document.
 *
 * 
 * Sets the encoding of a document. 
 * 
 *         
 *
 * 
 * This function only set the encoding of the document, it does not any conversions. The new encoding is used when e.g. saving the file.
 * 
 * 
 * 
 * 
 *         
 *
 */
void document_set_encoding (GeanyDocument *doc, const gchar *new_encoding);



/**
 * document_get_status_color: 
 * @doc:  The document to use.
 *
 * 
 * Gets the status color of the document, or %NULL if default widget coloring should be used. 
 * 
 *         
 *
 * 
 * Returned colors are red if the document has changes, green if the document is read-only or simply %NULL if the document is unmodified but writable.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  The color for the document or %NULL if the default color should be used. The color object is owned by Geany and should not be modified or freed.
 *
 * Since: 0.16
 */
const GdkColor* document_get_status_color (GeanyDocument *doc);



/**
 * document_index: 
 * @idx:  GeanyData::documents_array index.
 *
 * 
 * Accessor function for GeanyData::documents_array items. 
 * 
 *         
 *
 * 
 * Always check the returned document is valid (doc->is_valid). 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  The document, or %NULL if @idx is out of range.
 *
 * Since: 0.16
 */
GeanyDocument* document_index (gint idx);



/**
 * document_compare_by_display_name: 
 * @a:  GeanyDocument**.
 * @b:  GeanyDocument**.
 *
 * 
 * Compares documents by their display names. 
 * 
 *         
 *
 * 
 * This matches GCompareFunc for use with e.g. g_ptr_array_sort(). 'Display name' means the base name of the document's filename.
 * 
 * 
 * 
 * 
 * The arguments take the address of each document pointer. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Negative value if a < b; zero if a = b; positive value if a > b.
 *
 * Since: 0.21
 */
gint document_compare_by_display_name (gconstpointer a, gconstpointer b);



/**
 * document_compare_by_tab_order: 
 * @a:  GeanyDocument**.
 * @b:  GeanyDocument**.
 *
 * 
 * Compares documents by their tab order. 
 * 
 *         
 *
 * 
 * This matches GCompareFunc for use with e.g. g_ptr_array_sort().
 * 
 * 
 * The arguments take the address of each document pointer. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Negative value if a < b; zero if a = b; positive value if a > b.
 *
 * Since: 0.21 (GEANY_API_VERSION 209)
 */
gint document_compare_by_tab_order (gconstpointer a, gconstpointer b);



/**
 * document_compare_by_tab_order_reverse: 
 * @a:  GeanyDocument**.
 * @b:  GeanyDocument**.
 *
 * 
 * Compares documents by their tab order, in reverse order. 
 * 
 *         
 *
 * 
 * This matches GCompareFunc for use with e.g. g_ptr_array_sort().
 * 
 * 
 * The arguments take the address of each document pointer. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Negative value if a < b; zero if a = b; positive value if a > b.
 *
 * Since: 0.21 (GEANY_API_VERSION 209)
 */
gint document_compare_by_tab_order_reverse (gconstpointer a, gconstpointer b);



/**
 * document_get_type: 
 *
 * 
 * Gets the GType of GeanyDocument. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  the GeanyDocument type
 */
GType document_get_type (void);



/**
 * editor_get_indent_prefs: 
 * @editor: (nullable):  The editor, or %NULL to get the default indent prefs.
 *
 * 
 * Gets the indentation prefs for the editor. 
 * 
 *         
 *
 * 
 * Prefs can be different according to project or document. Always get a fresh result instead of keeping a pointer to it if the editor/project settings may have changed, or if this function has been called for a different editor. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The indent prefs.
 */
const GeanyIndentPrefs* editor_get_indent_prefs (GeanyEditor *editor);



/**
 * editor_get_word_at_pos: 
 * @editor:  The editor to operate on.
 * @pos:  The position where the word should be read from. May be -1 to use the current position.
 * @wordchars:  The wordchars to separate words. wordchars mean all characters to count as part of a word. May be %NULL to use the default wordchars, see GEANY_WORDCHARS.
 *
 * 
 * Finds the word at the position specified by @pos. 
 * 
 *         
 *
 * 
 * If any word is found, it is returned. Otherwise NULL is returned. Additional wordchars can be specified to define what to consider as a word.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  A newly-allocated string containing the word at the given @pos or %NULL. Should be freed when no longer needed.
 *
 * Since: 0.16
 */
gchar* editor_get_word_at_pos (GeanyEditor *editor, gint pos, const gchar *wordchars);



/**
 * editor_insert_text_block: 
 *
 * 
 * Inserts text, replacing \t tab chars (0x9) and \n newline chars (0xA) accordingly for the document. 
 * 
 *         
 *
 * 
 * 
 * 
 *  - Leading tabs are replaced with the correct indentation.
 * 
 *  - Non-leading tabs are replaced with spaces (except when using 'Tabs' indent type).
 * 
 *  - Newline chars are replaced with the correct line ending string. This is very useful for inserting code without having to handle the indent type yourself (Tabs & Spaces mode can be tricky). 
 * Make sure all \t tab chars in @text are intended as indent widths or alignment, not hard tabs, as those won't be preserved. 
 * 
 * 
 * 
 * This doesn't scroll the cursor in view afterwards. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void editor_insert_text_block (GeanyEditor *editor, const gchar *text, gint insert_pos, gint cursor_index, gint newline_indent_size, gboolean replace_newlines);



/**
 * editor_indicator_clear: 
 * @editor:  The editor to operate on.
 * @indic:  The indicator number to clear, this is a value of GeanyIndicator.
 *
 * 
 * Deletes all currently set indicators matching @indic in the @editor window. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void editor_indicator_clear (GeanyEditor *editor, gint indic);



/**
 * editor_indicator_set_on_line: 
 * @editor:  The editor to operate on.
 * @indic:  The indicator number to use, this is a value of GeanyIndicator.
 * @line:  The line number which should be marked.
 *
 * 
 * Sets an indicator @indic on @line. 
 * 
 *         
 *
 * 
 * Whitespace at the start and the end of the line is not marked.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void editor_indicator_set_on_line (GeanyEditor *editor, gint indic, gint line);



/**
 * editor_indicator_set_on_range: 
 * @editor:  The editor to operate on.
 * @indic:  The indicator number to use, this is a value of GeanyIndicator.
 * @start:  The starting position for the marker.
 * @end:  The ending position for the marker.
 *
 * 
 * Sets an indicator on the range specified by @start and @end. 
 * 
 *         
 *
 * 
 * No error checking or whitespace removal is performed, this should be done by the calling function if necessary.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void editor_indicator_set_on_range (GeanyEditor *editor, gint indic, gint start, gint end);



/**
 * editor_get_eol_char_mode: 
 * @editor: (nullable):  The editor to operate on, or %NULL to query the default value.
 *
 * 
 * Retrieves the end of line characters mode (LF, CR/LF, CR) in the given editor. 
 * 
 *         
 *
 * 
 * If @editor is %NULL, the default end of line characters are used.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The used end of line characters mode.
 *
 * Since: 0.20
 */
gint editor_get_eol_char_mode (GeanyEditor *editor);



/**
 * editor_get_eol_char_name: 
 * @editor: (nullable):  The editor to operate on, or %NULL to query the default value.
 *
 * 
 * Retrieves the localized name (for displaying) of the used end of line characters (LF, CR/LF, CR) in the given editor. 
 * 
 *         
 *
 * 
 * If @editor is %NULL, the default end of line characters are used.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The name of the end of line characters.
 *
 * Since: 0.19
 */
const gchar* editor_get_eol_char_name (GeanyEditor *editor);



/**
 * editor_get_eol_char_len: 
 * @editor: (nullable):  The editor to operate on, or %NULL to query the default value.
 *
 * 
 * Retrieves the length of the used end of line characters (LF, CR/LF, CR) in the given editor. 
 * 
 *         
 *
 * 
 * If @editor is %NULL, the default end of line characters are used. The returned value is 1 for CR and LF and 2 for CR/LF.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The length of the end of line characters.
 *
 * Since: 0.19
 */
gint editor_get_eol_char_len (GeanyEditor *editor);



/**
 * editor_get_eol_char: 
 * @editor: (nullable):  The editor to operate on, or %NULL to query the default value.
 *
 * 
 * Retrieves the used end of line characters (LF, CR/LF, CR) in the given editor. 
 * 
 *         
 *
 * 
 * If @editor is %NULL, the default end of line characters are used. The returned value is either "\n", "\r\n" or "\r".
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The end of line characters.
 *
 * Since: 0.19
 */
const gchar* editor_get_eol_char (GeanyEditor *editor);



/**
 * editor_set_indent_type: 
 * @editor:  Editor.
 * @type:  Indent type.
 *
 * 
 * Sets the indent type for @editor. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void editor_set_indent_type (GeanyEditor *editor, GeanyIndentType type);



/**
 * editor_set_indent_width: 
 * @editor:  Editor.
 * @width:  New indent width.
 *
 * 
 * Sets the indent width for @editor. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.27 (API 227)
 */
void editor_set_indent_width (GeanyEditor *editor, gint width);



/**
 * editor_goto_pos: 
 * @editor:  Editor.
 * @pos:  The position.
 * @mark:  Whether to set a mark on the position.
 *
 * 
 * Moves to position @pos, switching to the document if necessary, setting a marker if @mark is set. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if action has been performed, otherwise %FALSE.
 *
 * Since: 0.20
 */
gboolean editor_goto_pos (GeanyEditor *editor, gint pos, gboolean mark);



/**
 * editor_create_widget: 
 * @editor:  Editor settings.
 *
 * 
 * Creates a new Scintilla GtkWidget based on the settings for @editor. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer floating):  The new widget.
 *
 * Since: 0.15
 */
ScintillaObject* editor_create_widget (GeanyEditor *editor);



/**
 * editor_find_snippet: 
 * @editor: (nullable):  Editor or %NULL.
 * @snippet_name:  Snippet name.
 *
 * 
 * Gets snippet by name. 
 * 
 *         
 *
 * 
 * If @editor is passed, returns a snippet specific to the document filetype. If @editor is %NULL, returns a snippet from the default set.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  snippet or %NULL if it was not found. Must not be freed.
 */
const gchar* editor_find_snippet (GeanyEditor *editor, const gchar *snippet_name);



/**
 * editor_insert_snippet: 
 * @editor:  .
 * @pos:  .
 * @snippet:  .
 *
 * 
 * Replaces all special sequences in @snippet and inserts it at @pos. 
 * 
 *         
 *
 * 
 * If you insert at the current position, consider calling sci_scroll_caret() after this function. 
 * 
 * 
 *         
 *
 */
void editor_insert_snippet (GeanyEditor *editor, gint pos, const gchar *snippet);



/**
 * editor_get_type: 
 *
 * 
 * Gets the GType of GeanyEditor. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  the GeanyEditor type
 */
GType editor_get_type (void);



/**
 * encodings_get_charset_from_index: 
 * @idx:  GeanyEncodingIndex to retrieve the corresponding character set.
 *
 * 
 * Gets the character set name of the specified index e.g. 
 * 
 *         
 *
 * 
 * for use with document_set_encoding().
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  The charset according to idx, or %NULL if the index is invalid.
 *
 * Since: 0.13
 */
const gchar* encodings_get_charset_from_index (gint idx);



/**
 * encodings_convert_to_utf8_from_charset: 
 * @buffer:  The input string to convert.
 * @size:  The length of the string, or -1 if the string is nul-terminated.
 * @charset:  The charset to be used for conversion.
 * @fast:  %TRUE to only convert the input and skip extended checks on the converted string.
 *
 * 
 * Tries to convert @buffer into UTF-8 encoding from the encoding specified with @charset. 
 * 
 *         
 *
 * 
 * If @fast is not set, additional checks to validate the converted string are performed.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  If the conversion was successful, a newly allocated nul-terminated string, which must be freed with g_free(). Otherwise %NULL.
 */
gchar* encodings_convert_to_utf8_from_charset (const gchar *buffer, gssize size, const gchar *charset, gboolean fast);



/**
 * encodings_convert_to_utf8: 
 * @buffer:  the input string to convert.
 * @size:  the length of the string, or -1 if the string is nul-terminated.
 * @used_encoding: (out) (optional):  return location of the detected encoding of the input string, or %NULL.
 *
 * 
 * Tries to convert @buffer into UTF-8 encoding and store the detected original encoding in @used_encoding. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  If the conversion was successful, a newly allocated nul-terminated string, which must be freed with g_free(). Otherwise %NULL.
 */
gchar* encodings_convert_to_utf8 (const gchar *buffer, gssize size, gchar **used_encoding);



/**
 * filetypes_get_sorted_by_name: 
 *
 * 
 * Gets a list of filetype pointers sorted by name. 
 * 
 *         
 *
 * 
 * The list does not change on subsequent calls. 
 * See filetypes_by_title. 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (element-type GeanyFiletype) (transfer none):  The list - do not free.
 */
const GSList* filetypes_get_sorted_by_name (void);



/**
 * filetypes_detect_from_file: 
 * @utf8_filename:  The filename in UTF-8 encoding.
 *
 * 
 * Detects filetype based on a shebang line in the file or the filename extension. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  The detected filetype for @utf8_filename or filetypes[GEANY_FILETYPES_NONE] if it could not be detected.
 */
GeanyFiletype* filetypes_detect_from_file (const gchar *utf8_filename);



/**
 * filetypes_lookup_by_name: 
 * @name:  Filetype name.
 *
 * 
 * Finds a filetype pointer from its @name field. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  The filetype found, or %NULL.
 *
 * Since: 0.15
 */
GeanyFiletype* filetypes_lookup_by_name (const gchar *name);



/**
 * filetypes_index: 
 * @idx:  filetypes_array index.
 *
 * 
 * Accessor function for GeanyData::filetypes_array items. 
 * 
 *         
 *
 * 
 * Example:
 * |[<!-- language="C" -->
 *   ft = filetypes_index(GEANY_FILETYPES_C); 
 * ]| 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none) (nullable):  The filetype, or %NULL if @idx is out of range.
 *
 * Since: 0.16
 */
GeanyFiletype* filetypes_index (gint idx);



/**
 * filetypes_get_display_name: 
 * @ft:  .
 *
 * 
 * Gets ft->name or a translation for filetype None. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  .
 *
 * Since: Geany 0.20
 */
const gchar* filetypes_get_display_name (GeanyFiletype *ft);



/**
 * filetype_get_type: 
 *
 * 
 * Gets the GType of GeanyFiletype. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  the GeanyFiletype type
 */
GType filetype_get_type (void);



/**
 * geany_object_get_type: 
 *
 * 
 * Get the GObject-derived GType for GeanyObject. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  GeanyObject type
 */
GType geany_object_get_type (void);



/**
 * highlighting_set_styles: 
 * @sci:  Scintilla widget.
 * @ft:  Filetype settings to use.
 *
 * 
 * Sets up highlighting and other visual settings. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void highlighting_set_styles (ScintillaObject *sci, GeanyFiletype *ft);



/**
 * highlighting_get_style: 
 * @ft_id:  Filetype ID, e.g. GEANY_FILETYPES_DIFF.
 * @style_id:  A Scintilla lexer style, e.g. SCE_DIFF_ADDED. See scintilla/include/SciLexer.h.
 *
 * 
 * Retrieves a style @style_id for the filetype @ft_id. 
 * 
 *         
 *
 * 
 * If the style was not already initialised (e.g. by by opening a file of this type), it will be initialised. The returned pointer is owned by Geany and must not be freed. 
 * 
 * See Scintilla messages SCI_STYLEGETFORE, etc, for use with scintilla_send_message(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A pointer to the style struct.
 */
const GeanyLexerStyle* highlighting_get_style (gint ft_id, gint style_id);



/**
 * highlighting_is_string_style: 
 * @lexer:  Scintilla lexer type (SCLEX_*).
 * @style:  Scintilla style (SCE_*).
 *
 * 
 * Checks whether the given style is a string for the given lexer. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the style is a string, %FALSE otherwise.
 */
gboolean highlighting_is_string_style (gint lexer, gint style);



/**
 * highlighting_is_comment_style: 
 * @lexer:  Scintilla lexer type (SCLEX_*).
 * @style:  Scintilla style (SCE_*).
 *
 * 
 * Checks whether the given style is a comment for the given lexer. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the style is a comment, %FALSE otherwise.
 */
gboolean highlighting_is_comment_style (gint lexer, gint style);



/**
 * highlighting_is_code_style: 
 * @lexer:  Scintilla lexer type (SCLEX_*).
 * @style:  Scintilla style (SCE_*).
 *
 * 
 * Checks whether the given style is normal code (not string, comment, preprocessor, etc). 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the style is code, %FALSE otherwise.
 */
gboolean highlighting_is_code_style (gint lexer, gint style);



/**
 * keybindings_get_modifiers: 
 * @mods:  GdkModifierType mask.
 *
 * 
 * Gets significant modifiers from a GdkModifierType mask. 
 * 
 *         
 *
 * 
 * The set of significant modifiers corresponds to the default modifier mask as returned by gtk_accelerator_get_default_mod_mask(). In addition, it improves the Command key handling on OS X by adding GEANY_PRIMARY_MOD_MASK when needed. For this reason it is preferred to use this function instead of gtk_accelerator_set_default_mod_mask(). 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Significant modifiers from the mask.
 *
 * Since: 1.25.
 */
GdkModifierType keybindings_get_modifiers (GdkModifierType mods);



/**
 * keybindings_get_item: 
 * @group:  Group.
 * @key_id:  Keybinding index for the group.
 *
 * 
 * Looks up a keybinding item. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  The keybinding.
 *
 * Since: 0.19.
 */
GeanyKeyBinding* keybindings_get_item (GeanyKeyGroup *group, gsize key_id);



/**
 * keybindings_set_item: (skip): 
 * @group:  Group.
 * @key_id:  Keybinding index for the group.
 * @callback: (nullable):  Function to call when activated, or %NULL to use the group callback. Usually it's better to use the group callback instead - see plugin_set_key_group().
 * @key:  Default key, e.g. GDK_j (must be lower case), but usually 0 for unset.
 * @mod:  Default modifier, e.g. GDK_CONTROL_MASK, but usually 0 for unset.
 * @kf_name:  Key name used for this item in the keybindings configuration file, i.e. "menu_new".
 * @label:  Label used in the preferences dialog keybindings tab. May contain underscores - these won't be displayed.
 * @menu_item: (nullable):  Optional widget to set an accelerator for, or %NULL.
 *
 * 
 *   Fills a GeanyKeyBinding struct item. 
 * 
 *         
 *
 * 
 * Always set @key and @mod to 0, otherwise you will likely cause conflicts with the user's custom, other plugin's keybindings or future default keybindings. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The keybinding - normally this is ignored.
 */
GeanyKeyBinding* keybindings_set_item (GeanyKeyGroup *group, gsize key_id, GeanyKeyCallback callback, guint key, GdkModifierType mod, const gchar *kf_name, const gchar *label, GtkWidget *menu_item);



/**
 * keybindings_set_item_full: 
 * @group:  Group.
 * @key_id:  Keybinding index for the group.
 * @key:  Default key, e.g. GDK_j (must be lower case), but usually 0 for unset.
 * @mod:  Default modifier, e.g. GDK_CONTROL_MASK, but usually 0 for unset.
 * @kf_name:  Key name used for this item in the keybindings configuration file, i.e. "menu_new".
 * @label:  Label used in the preferences dialog keybindings tab. May contain underscores - these won't be displayed.
 * @menu_item: (nullable):  Optional widget to set an accelerator for, or %NULL.
 * @cb: (nullable):  New-style callback to be called when activated, or %NULL to use the group callback.
 * @pdata:  Plugin-specific data passed back to the callback @cb.
 * @destroy_notify:  Function that is invoked to free the plugin data when not needed anymore.
 *
 * 
 * Creates a new keybinding using a GeanyKeyBindingFunc and attaches it to a keybinding group. 
 * 
 *         
 *
 * 
 * If given the callback should return %TRUE if the keybinding was handled, otherwise %FALSE to allow other callbacks to be run. This allows for multiplexing keybindings on the same keys, depending on the focused widget (or context). If the callback is NULL the group's callback will be invoked, but the same rule applies.
 * 
 * 
 * 
 * 
 * See See plugin_set_key_group_full 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  The keybinding - normally this is ignored.
 *
 * Since: 1.26 (API 226)
 */
GeanyKeyBinding* keybindings_set_item_full (GeanyKeyGroup *group, gsize key_id, guint key, GdkModifierType mod, const gchar *kf_name, const gchar *label, GtkWidget *menu_item, GeanyKeyBindingFunc cb, gpointer pdata, GDestroyNotify destroy_notify);



/**
 * keybindings_load_keyfile: 
 *
 * 
 * Reloads keybinding settings from configuration file. 
 * 
 *         
 *
 * 
 * Normally plugins do not need to call this function as it is called automatically when a the plugin is activated. However, plugins which need to create keybindings dynamically and reload them when needed should call this function after all keybindings have been updated with plugin_set_key_group() and keybindings_set_item() calls - this makes sure that the corresponding user keybinding shortcuts are applied.
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.32 (API 233)
 */
void keybindings_load_keyfile (void);



/**
 * keybindings_send_command: 
 * @group_id:  GeanyKeyGroupID keybinding group index that contains the @key_id keybinding.
 * @key_id:  GeanyKeyBindingID keybinding index.
 *
 * 
 * Mimics a (built-in only) keybinding action. 
 * 
 *         
 *
 * 
 * Example:
 * |[<!-- language="C" -->
 *   keybindings_send_command(GEANY_KEY_GROUP_FILE, GEANY_KEYS_FILE_OPEN); 
 * ]| 
 * 
 * 
 *         
 *
 */
void keybindings_send_command (guint group_id, guint key_id);



/**
 * main_is_realized: 
 *
 * 
 * Checks whether the main window has been realized. 
 * 
 *         
 *
 * 
 * This is an easy indicator whether Geany is right now starting up (main window is not yet realized) or whether it has finished the startup process (main window is realized). This is because the main window is realized (i.e. actually drawn on the screen) at the end of the startup process.
 * 
 * Maybe you want to use the  to get notified about the completed startup process.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the Geany main window has been realized or %FALSE otherwise.
 *
 * Since: 0.19
 */
gboolean main_is_realized (void);



/**
 * main_locale_init: 
 * @locale_dir:  The location where the translation files should be searched. This is usually the LOCALEDIR macro, defined by the build system. E.g. $prefix/share/locale. Only used on non-Windows systems. On Windows, the directory is determined by g_win32_get_package_installation_directory().
 * @package:  The package name, usually this is the GETTEXT_PACKAGE macro, defined by the build system.
 *
 * 
 * Initialises the gettext translation system. 
 * 
 *         
 *
 * 
 * This is a convenience function to set up gettext for internationalisation support in external plugins. You should call this function early in plugin_init(). If the macro HAVE_LOCALE_H is defined, setlocale(LC_ALL, "") is called. The codeset for the message translations is set to UTF-8.
 * 
 * Note that this function only setups the gettext textdomain for you. You still have to adjust the build system of your plugin to get internationalisation support working properly.
 * 
 * If you have already used PLUGIN_SET_TRANSLATABLE_INFO() you don't need to call main_locale_init() again as it has already been done.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void main_locale_init (const gchar *locale_dir, const gchar *package);



/**
 * main_reload_configuration: 
 *
 * 
 * Reloads most of Geany's configuration files without restarting. 
 * 
 *         
 *
 * 
 * Currently the following files are reloaded: all template files, also new file templates and the 'New (with template)' menus will be updated, Snippets (snippets.conf), filetype extensions (filetype_extensions.conf), and 'settings' and 'build_settings' sections of the filetype definition files.
 * 
 * Plugins may call this function if they changed any of these files (e.g. a configuration file editor plugin).
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.15
 */
void main_reload_configuration (void);



/**
 * msgwin_set_messages_dir: 
 * @messages_dir:  The directory.
 *
 * 
 * Sets the Messages path for opening any parsed filenames without absolute path from message lines. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void msgwin_set_messages_dir (const gchar *messages_dir);



/**
 * msgwin_compiler_add: 
 * @msg_color:  A color to be used for the text. It must be an element of MsgColors.
 * @format:  printf()-style format string.
 * @...:  Arguments for the format string.
 *
 * 
 * Adds a formatted message in the compiler tab treeview in the messages window. 
 * 
 *         
 *
 * 
 * 
 * See msgwin_compiler_add_string()
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void msgwin_compiler_add (gint msg_color, const gchar *format,...);



/**
 * msgwin_compiler_add_string: 
 * @msg_color:  A color to be used for the text. It must be an element of MsgColors.
 * @msg:  Compiler message to be added.
 *
 * 
 * Adds a new message in the compiler tab treeview in the messages window. 
 * 
 *         
 *
 * 
 * 
 * See msgwin_compiler_add()
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.34 (API 236)
 */
void msgwin_compiler_add_string (gint msg_color, const gchar *msg);



/**
 * msgwin_msg_add: 
 * @msg_color:  A color to be used for the text. It must be an element of MsgColors.
 * @line:  The document's line where the message belongs to. Set to -1 to ignore.
 * @doc: (nullable):  The document. Set to %NULL to ignore.
 * @format:  printf()-style format string.
 * @...:  Arguments for the format string.
 *
 * 
 * Adds a formatted message in the messages tab treeview in the messages window. 
 * 
 *         
 *
 * 
 * If @line and @doc are set, clicking on this line jumps into the file which is specified by @doc into the line specified with @line.
 * 
 * 
 * See msgwin_msg_add_string()
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void msgwin_msg_add (gint msg_color, gint line, GeanyDocument *doc, const gchar *format,...);



/**
 * msgwin_msg_add_string: 
 * @msg_color:  A color to be used for the text. It must be an element of MsgColors.
 * @line:  The document's line where the message belongs to. Set to -1 to ignore.
 * @doc: (nullable):  The document. Set to %NULL to ignore.
 * @string:  Message to be added.
 *
 * 
 * Adds a new message in the messages tab treeview in the messages window. 
 * 
 *         
 *
 * 
 * If @line and @doc are set, clicking on this line jumps into the file which is specified by @doc into the line specified with @line.
 * 
 * 
 * See msgwin_msg_add()
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.34 (API 236)
 */
void msgwin_msg_add_string (gint msg_color, gint line, GeanyDocument *doc, const gchar *string);



/**
 * msgwin_status_add_string: 
 * @string:  Status message to be logged.
 *
 * 
 * Logs a new status message @without setting the status bar. 
 * 
 *         
 *
 * 
 * Use ui_set_statusbar() to display text on the statusbar.
 * 
 * 
 * See msgwin_status_add()
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.34 (API 236)
 */
void msgwin_status_add_string (const gchar *string);



/**
 * msgwin_status_add: 
 * @format:  printf()-style format string.
 * @...:  Arguments for the format string.
 *
 * 
 * Logs a formatted status message @without setting the status bar. 
 * 
 *         
 *
 * 
 * Use ui_set_statusbar() to display text on the statusbar.
 * 
 * 
 * See msgwin_status_add_string()
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.12
 */
void msgwin_status_add (const gchar *format,...);



/**
 * msgwin_switch_tab: 
 * @tabnum:  An index of a tab in the messages window. Valid values are all elements of MessageWindowTabNum.
 * @show:  Whether to show the messages window at all if it was hidden before.
 *
 * 
 * Switches to the given notebook tab of the messages window. 
 * 
 *         
 *
 * 
 * The messages window is shown if it was previously hidden and @show is set to %TRUE.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.15
 */
void msgwin_switch_tab (gint tabnum, gboolean show);



/**
 * msgwin_clear_tab: 
 * @tabnum:  An index of a tab in the messages window which should be cleared. Valid values are MSG_STATUS, MSG_COMPILER and MSG_MESSAGE.
 *
 * 
 * Removes all messages from a tab specified by @tabnum in the messages window. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.15
 */
void msgwin_clear_tab (gint tabnum);



/**
 * navqueue_goto_line: 
 * @old_doc:  The document of the previous position, if set as invalid (%NULL) then no old position is set
 * @new_doc:  The document of the new position, must be valid.
 * @line:  the line number of the new position. It is counted with 1 as the first line, not 0.
 *
 * 
 * Adds old file position and new file position to the navqueue, then goes to the new position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the cursor has changed the position to @line or %FALSE otherwise.
 */
gboolean navqueue_goto_line (GeanyDocument *old_doc, GeanyDocument *new_doc, gint line);



/**
 * geany_plugin_register: 
 * @plugin:  The plugin provided by Geany
 * @api_version:  The API version the plugin is compiled against (pass GEANY_API_VERSION)
 * @min_api_version:  The minimum API version required by the plugin
 * @abi_version:  The exact ABI version the plugin is compiled against (pass GEANY_ABI_VERSION)
 *
 * 
 * Register a plugin to Geany. 
 * 
 *         
 *
 * 
 * The plugin will show up in the plugin manager. The user can interact with it based on the functions it provides and installed GUI elements.
 * 
 * You must initialize the info and funcs fields of GeanyPlugin appropriately prior to calling this, otherwise registration will fail. For info at least a valid name must be set (possibly localized). For funcs, at least init() and cleanup() functions must be implemented and set.
 * 
 * The return value must be checked. It may be FALSE if the plugin failed to register which can mainly happen for two reasons (future Geany versions may add new failure conditions):
 * 
 *  - Not all mandatory fields of GeanyPlugin have been set.
 * 
 *  - The ABI or API versions reported by the plugin are incompatible with the running Geany.
 * 
 * 
 * 
 * 
 * Do not call this directly. Use GEANY_PLUGIN_REGISTER() instead which automatically handles @api_version and @abi_version.
 * 
 * 
 * 
 * 
 * See GEANY_PLUGIN_REGISTER() 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  TRUE if the plugin was successfully registered. Otherwise FALSE.
 *
 * Since: 1.26 (API 225)
 */
gboolean geany_plugin_register (GeanyPlugin *plugin, gint api_version, gint min_api_version, gint abi_version);



/**
 * geany_plugin_register_full: 
 * @plugin:  The plugin provided by Geany.
 * @api_version:  The API version the plugin is compiled against (pass GEANY_API_VERSION).
 * @min_api_version:  The minimum API version required by the plugin.
 * @abi_version:  The exact ABI version the plugin is compiled against (pass GEANY_ABI_VERSION).
 * @pdata:  Pointer to the plugin-defined data. Must not be %NULL.
 * @free_func:  Function used to deallocate @pdata, may be %NULL.
 *
 * 
 * Register a plugin to Geany, with plugin-defined data. 
 * 
 *         
 *
 * 
 * This is a variant of geany_plugin_register() that also allows to set the plugin-defined data. Refer to that function for more details on registering in general.
 * 
 * pdata is the pointer going to be passed to the individual plugin callbacks of GeanyPlugin::funcs. When the plugin module is unloaded, free_func is invoked on pdata, which connects the data to the plugin's module life time.
 * 
 * You cannot use geany_plugin_set_data() after registering with this function. Use geany_plugin_register() if you need to.
 * 
 * Do not call this directly. Use GEANY_PLUGIN_REGISTER_FULL() instead which automatically handles api_version and abi_version.
 * 
 * 
 * 
 * 
 * See GEANY_PLUGIN_REGISTER_FULL() 
 * 
 * 
 * 
 * See geany_plugin_register() 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  TRUE if the plugin was successfully registered. Otherwise FALSE.
 *
 * Since: 1.26 (API 225)
 */
gboolean geany_plugin_register_full (GeanyPlugin *plugin, gint api_version, gint min_api_version, gint abi_version, gpointer pdata, GDestroyNotify free_func);



/**
 * geany_plugin_register_proxy: 
 * @plugin:  The pointer to the plugin's GeanyPlugin instance
 * @extensions:  A NULL-terminated string array of file extensions, excluding the dot.
 *
 * 
 * Register the plugin as a proxy for other plugins. 
 * 
 *         
 *
 * 
 * Proxy plugins register a list of file extensions and a set of callbacks that are called appropriately. A plugin can be a proxy for multiple types of sub-plugins by handling separate file extensions, however they must share the same set of hooks, because this function can only be called at most once per plugin.
 * 
 * Each callback receives the plugin-defined data as parameter (see geany_plugin_register()). The callbacks must be set prior to calling this, by assigning to @plugin->proxy_funcs. GeanyProxyFuncs::load and GeanyProxyFuncs::unload must be implemented.
 * 
 * Nested proxies are unsupported at this point (TODO).
 * 
 * It is entirely up to the proxy to provide access to Geany's plugin API. Native code can naturally call Geany's API directly, for interpreted languages the proxy has to implement some kind of bindings that the plugin can use.
 * 
 * 
 * 
 * See proxy for detailed documentation and an example.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the proxy was successfully registered, otherwise %FALSE
 *
 * Since: 1.26 (API 226)
 */
gboolean geany_plugin_register_proxy (GeanyPlugin *plugin, const gchar **extensions);



/**
 * plugin_version_check: 
 * @abi:  ABI version Geany was compiled with
 *
 * 
 * Use the PLUGIN_VERSION_CHECK() macro instead. 
 * 
 *         
 *
 * 
 * Required by Geany.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The API version the plugin was compiled with, or -1 if the plugin is incompatible.
 */
gint plugin_version_check (gint abi);



/**
 * plugin_set_info: 
 * @info:  The data struct which should be initialized by this function.
 *
 * 
 * Use the PLUGIN_SET_INFO() macro to define it. 
 * 
 *         
 *
 * 
 * Required by Geany. This function is called before the plugin is initialized, so Geany can read the plugin's name. 
 * 
 * 
 *         
 *
 */
void plugin_set_info (PluginInfo *info);



/**
 * plugin_configure: 
 * @dialog:  The plugin preferences dialog widget - this should only be used to connect the "response" signal. If settings should be read from the dialog, the response will be either GTK_RESPONSE_OK or GTK_RESPONSE_APPLY.
 *
 * 
 * Called before showing the plugin preferences dialog for multiple plugins. 
 * 
 *         
 *
 * 
 * Can be omitted when not needed. The dialog will show all plugins that support this symbol together. 
 * 
 * Using Stash  can make implementing preferences easier. 
 * 
 * 
 * 
 * See plugin_configure_single(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer floating):  A container widget holding preference widgets.
 */
GtkWidget* plugin_configure (GtkDialog *dialog);



/**
 * plugin_configure_single: 
 * @parent:  Pass this as the parent widget if showing a dialog.
 *
 * 
 * Called when a plugin should show a preferences dialog, if plugin_configure() has not been implemented. 
 * 
 *         
 *
 * 
 * It's better to implement plugin_configure() instead, but this is simpler. This does not integrate as well with the multiple-plugin dialog. 
 * 
 * 
 * 
 * 
 * See plugin_configure(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void plugin_configure_single (GtkWidget *parent);



/**
 * plugin_init: 
 * @data:  The same as geany_data.
 *
 * 
 * Called after loading the plugin. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void plugin_init (GeanyData *data);



/**
 * plugin_cleanup: 
 *
 * 
 * Called before unloading the plugin. 
 * 
 *         
 *
 * 
 * Required for normal plugins - it should undo everything done in plugin_init() - e.g. destroy menu items, free memory. 
 * 
 *         
 *
 */
void plugin_cleanup ();



/**
 * plugin_help: 
 *
 * 
 * Called whenever the plugin should show its documentation (if any). 
 * 
 *         
 *
 * 
 * This may open a dialog, a browser with a website or a local installed HTML help file (see utils_open_browser()) or something else. Can be omitted when not needed. 
 * 
 *         
 *
 */
void plugin_help ();



/**
 * geany_api_version: 
 *
 * 
 * Returns the runtime API version Geany was compiled with. 
 * 
 *         
 *
 * 
 * Unlike GEANY_API_VERSION this version is the value of that define at the time when Geany itself was compiled. This allows to establish soft dependencies which are resolved at runtime depending on Geany's API version.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Geany's API version
 *
 * Since: 1.30 (API 231)
 */
gint geany_api_version (void);



/**
 * plugin_add_toolbar_item: 
 * @plugin:  Must be geany_plugin.
 * @item:  The item to add.
 *
 * 
 * Inserts a toolbar item before the Quit button, or after the previous plugin toolbar item. 
 * 
 *         
 *
 * 
 * A separator is added on the first call to this function, and will be shown when @item is shown; hidden when @item is hidden. You should still destroy @item yourself, usually in plugin_cleanup(). 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void plugin_add_toolbar_item (GeanyPlugin *plugin, GtkToolItem *item);



/**
 * plugin_module_make_resident: 
 * @plugin:  Must be geany_plugin.
 *
 * 
 * Ensures that a plugin's module (*.so) will never be unloaded. 
 * 
 *         
 *
 * 
 * This is necessary if you register new GTypes in your plugin, e.g. when using own classes using the GObject system.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void plugin_module_make_resident (GeanyPlugin *plugin);



/**
 * plugin_signal_connect: (skip): 
 * @plugin:  Must be geany_plugin.
 * @object: (nullable):  Object to connect to, or %NULL when using Geany signals .
 * @signal_name:  The name of the signal. For a list of available signals, please see the Signal documentation .
 * @after:  Set to %TRUE to call your handler after the main signal handlers have been called (if supported by @signal_name).
 * @callback:  The function to call when the signal is emitted.
 * @user_data:  The user data passed to the signal handler.
 *
 * 
 *   Connects a signal which will be disconnected on unloading the plugin, to prevent a possible segfault. 
 * 
 *         
 *
 * 
 * 
 * See plugin_callbacks.
 * 
 * 
 * 
 * Before version 1.25 (API < 218), this should only be used on objects that outlive the plugin, never on objects that will get destroyed before the plugin is unloaded. For objects created and destroyed by the plugin, you can simply use g_signal_connect(), since all handlers are disconnected when the object is destroyed anyway. For objects that may or may not outlive the plugin (like a document's , which is destroyed when the document is closed), you currently have to manually handle both situations, when the plugin is unloaded before the object is destroyed (and then, you have to disconnect the signal on plugin_cleanup()), and when the object is destroyed during the plugin's lifetime (in which case you cannot and should not disconnect manually in plugin_cleanup() since it already has been disconnected and the object has been destroyed), and disconnect yourself or not as appropriate. 
 * 
 * 
 * 
 * Since version 1.25 (API >= 218), the object lifetime is watched and so the above restriction does not apply. However, for objects destroyed by the plugin, g_signal_connect() is safe and has lower overhead. 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void plugin_signal_connect (GeanyPlugin *plugin, GObject *object, const gchar *signal_name, gboolean after, GCallback callback, gpointer user_data);



/**
 * plugin_timeout_add: (skip): 
 * @plugin:  Must be geany_plugin.
 * @interval:  The time between calls to the function, in milliseconds.
 * @function:  The function to call after the given timeout.
 * @data:  The user data passed to the function.
 *
 * 
 *   Adds a GLib main loop timeout callback that will be removed when unloading the plugin, preventing it to run after the plugin has been unloaded (which may lead to a segfault). 
 * 
 *         
 *
 * 
 * 
 * 
 * See g_timeout_add() 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  the ID of the event source (you generally won't need it, or better use g_timeout_add() directly if you want to manage this event source manually).
 *
 * Since: 0.21, plugin API 205.
 */
guint plugin_timeout_add (GeanyPlugin *plugin, guint interval, GSourceFunc function, gpointer data);



/**
 * plugin_timeout_add_seconds: (skip): 
 * @plugin:  Must be geany_plugin.
 * @interval:  The time between calls to the function, in seconds.
 * @function:  The function to call after the given timeout.
 * @data:  The user data passed to the function.
 *
 * 
 *   Adds a GLib main loop timeout callback that will be removed when unloading the plugin, preventing it to run after the plugin has been unloaded (which may lead to a segfault). 
 * 
 *         
 *
 * 
 * 
 * 
 * See g_timeout_add_seconds() 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  the ID of the event source (you generally won't need it, or better use g_timeout_add_seconds() directly if you want to manage this event source manually).
 *
 * Since: 0.21, plugin API 205.
 */
guint plugin_timeout_add_seconds (GeanyPlugin *plugin, guint interval, GSourceFunc function, gpointer data);



/**
 * plugin_idle_add: (skip): 
 * @plugin:  Must be geany_plugin.
 * @function:  The function to call in IDLE time.
 * @data:  The user data passed to the function.
 *
 * 
 *   Adds a GLib main loop IDLE callback that will be removed when unloading the plugin, preventing it to run after the plugin has been unloaded (which may lead to a segfault). 
 * 
 *         
 *
 * 
 * 
 * 
 * See g_idle_add() 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  the ID of the event source (you generally won't need it, or better use g_idle_add() directly if you want to manage this event source manually).
 *
 * Since: 0.21, plugin API 205.
 */
guint plugin_idle_add (GeanyPlugin *plugin, GSourceFunc function, gpointer data);



/**
 * plugin_set_key_group: (skip): 
 * @plugin:  Must be geany_plugin.
 * @section_name:  Name of the section used for this group in the keybindings configuration file, i.e. "html_chars".
 * @count:  Number of keybindings for the group.
 * @callback: (nullable):  Group callback, or %NULL if you only want individual keybinding callbacks.
 *
 * 
 *   Sets up or resizes a keybinding group for the plugin. 
 * 
 *         
 *
 * 
 * You should then call keybindings_set_item() for each keybinding in the group. 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The plugin's keybinding group.
 *
 * Since: 0.19.
 */
GeanyKeyGroup* plugin_set_key_group (GeanyPlugin *plugin, const gchar *section_name, gsize count, GeanyKeyGroupCallback callback);



/**
 * plugin_set_key_group_full: 
 * @plugin:  Must be geany_plugin.
 * @section_name:  Name of the section used for this group in the keybindings configuration file, i.e. "html_chars".
 * @count:  Number of keybindings for the group.
 * @cb: (nullable):  New-style group callback, or %NULL if you only want individual keybinding callbacks.
 * @pdata:  Plugin specific data, passed to the group callback @cb.
 * @destroy_notify:  Function that is invoked to free the plugin data when not needed anymore.
 *
 * 
 * Sets up or resizes a keybinding group for the plugin. 
 * 
 *         
 *
 * 
 * You should then call keybindings_set_item() or keybindings_set_item_full() for each keybinding in the group. 
 * 
 * 
 * See See keybindings_set_item 
 * 
 * 
 * 
 * See See keybindings_set_item_full 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  The plugin's keybinding group.
 *
 * Since: 1.26 (API 226)
 */
GeanyKeyGroup* plugin_set_key_group_full (GeanyPlugin *plugin, const gchar *section_name, gsize count, GeanyKeyGroupFunc cb, gpointer pdata, GDestroyNotify destroy_notify);



/**
 * plugin_show_configure: 
 * @plugin:  Must be geany_plugin.
 *
 * 
 * Shows the plugin's configure dialog. 
 * 
 *         
 *
 * 
 * The plugin must implement one of the plugin_configure() or plugin_configure_single() symbols. 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.19.
 */
void plugin_show_configure (GeanyPlugin *plugin);



/**
 * plugin_builder_connect_signals: 
 * @plugin:  Must be geany_plugin.
 * @builder:  The GtkBuilder to connect signals with.
 * @user_data:  User data to pass to the connected signal handlers.
 *
 * 
 * Allows auto-connecting Glade/GtkBuilder signals in plugins. 
 * 
 *         
 *
 * 
 * When a plugin uses GtkBuilder to load some UI from file/string, the gtk_builder_connect_signals() function is unable to automatically connect to the plugin's signal handlers. A plugin could itself use the gtk_builder_connect_signals_full() function to automatically connect to the signal handler functions by loading it's GModule and retrieving pointers to the handler functions, but rather than each plugin having to do that, this function handles it automatically.
 * 
 * 
 * |[<!-- language="C" -->
 *   ...
 *   GeanyPlugin *geany_plugin;
 *   G_MODULE_EXPORT void
 *   myplugin_button_clicked(GtkButton *button, gpointer user_data)
 *   {
 *     g_print("Button pressed\n");
 *   }
 *   void plugin_init(GeanyData *data)
 *   {
 *     GtkBuilder *builder = gtk_builder_new();
 *     gtk_builder_add_from_file(builder, "gui.glade", NULL);
 *     plugin_builder_connect_signals(geany_plugin, builder, NULL);
 *     ...
 *   }
 * ]|
 * 
 * It's important that you prefix your callback handlers with a plugin-specific prefix to avoid clashing with other plugins since the function symbols will be exported process-wide.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.24, plugin API 217.
 */
void plugin_builder_connect_signals (GeanyPlugin *plugin, GtkBuilder *builder, gpointer user_data);



/**
 * geany_plugin_get_data: 
 * @plugin:  The plugin provided by Geany
 *
 * 
 * Get the additional data that corresponds to the plugin. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * See geany_plugin_set_data() 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The data corresponding to the plugin or %NULL if none set.
 *
 * Since: 1.32 (API 234)
 */
gpointer geany_plugin_get_data (const GeanyPlugin *plugin);



/**
 * geany_plugin_set_data: 
 * @plugin:  The plugin provided by Geany
 * @pdata:  The plugin's data to associate, must not be %NULL
 * @free_func:  The destroy notify
 *
 * 
 * Add additional data that corresponds to the plugin. 
 * 
 *         
 *
 * 
 * pdata is the pointer going to be passed to the individual plugin callbacks of GeanyPlugin::funcs. When the plugin is cleaned up, free_func is invoked for the data, which connects the data to the time the plugin is enabled.
 * 
 * One intended use case is to set GObjects as data and have them destroyed automatically by passing g_object_unref() as @free_func, so that member functions can be used for the GeanyPluginFuncs (via wrappers) but you can set completely custom data.
 * 
 * Be aware that this can only be called once and only by plugins registered via geany_plugin_register(). So-called legacy plugins cannot use this function.
 * 
 * This function must not be called if the plugin was registered with geany_plugin_register_full().
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.26 (API 225)
 */
void geany_plugin_set_data (GeanyPlugin *plugin, gpointer pdata, GDestroyNotify free_func);



/**
 * plugin_get_document_data: 
 * @plugin:  The plugin who attached the data.
 * @doc:  The document which the data was attached to.
 * @key:  The key name of the attached data.
 *
 * 
 * Retrieve plugin-specific data attached to a document. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * See plugin_set_document_data plugin_set_document_data_full 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The attached data pointer or %NULL if the key is not found for the given plugin.
 *
 * Since: 1.29 (Plugin API 228)
 */
gpointer plugin_get_document_data (struct GeanyPlugin *plugin, struct GeanyDocument *doc, const gchar *key);



/**
 * plugin_set_document_data: 
 * @plugin:  The plugin attaching data to the document.
 * @doc:  The document to attach the data to.
 * @key:  The key name for the data.
 * @data:  The pointer to attach to the document.
 *
 * 
 * Attach plugin-specific data to a document. 
 * 
 *         
 *
 * 
 * 
 * 
 * See plugin_get_document_data plugin_set_document_data_full 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.29 (Plugin API 228)
 */
void plugin_set_document_data (struct GeanyPlugin *plugin, struct GeanyDocument *doc, const gchar *key, gpointer data);



/**
 * plugin_set_document_data_full: 
 * @plugin:  The plugin attaching data to the document.
 * @doc:  The document to attach the data to.
 * @key:  The key name for the data.
 * @data:  The pointer to attach to the document.
 * @free_func:  The function to call with data when removed.
 *
 * 
 * Attach plugin-specific data and a free function to a document. 
 * 
 *         
 *
 * 
 * This is useful for plugins who want to keep some additional data with the document and even have it auto-released appropriately (see below).
 * 
 * This is a simple example showing how a plugin might use this to attach a string to each document and print it when the document is saved:
 * 
 * 
 * |[<!-- language="C" -->
 *   void on_document_open(GObject *unused, GeanyDocument *doc, GeanyPlugin *plugin)
 *   {
 *       plugin_set_document_data_full(plugin, doc, "my-data",
 *           g_strdup("some-data"), g_free);
 *   }
 *   void on_document_save(GObject *unused, GeanyDocument *doc, GeanyPlugin *plugin)
 *   {
 *       const gchar *some_data = plugin_get_document_data(plugin, doc, "my-data");
 *       g_print("my-data: %s", some_data);
 *   }
 *   gboolean plugin_init(GeanyPlugin *plugin, gpointer unused)
 *   {
 *       plugin_signal_connect(plugin, NULL, "document-open", TRUE,
 *           G_CALLBACK(on_document_open), plugin);
 *       plugin_signal_connect(plugin, NULL, "document-new", TRUE,
 *           G_CALLBACK(on_document_open), plugin);
 *       plugin_signal_connect(plugin, NULL, "document-save", TRUE,
 *           G_CALLBACK(on_document_save), plugin);
 *       return TRUE;
 *   }
 *   void geany_load_module(GeanyPlugin *plugin)
 *   {
 *     // ...
 *     plugin->funcs->init = plugin_init;
 *     // ...
 *   }
 * ]|
 * 
 * The @free_func can be used to tie the lifetime of the data to that of the @doc and/or the @plugin. The @free_func will be called in any of the following cases:
 * 
 * 
 * 
 *  - When a document is closed.
 * 
 *  - When the plugin is unloaded.
 * 
 *  - When the document data is set again using the same key.
 * 
 * 
 * 
 * 
 * 
 * 
 * See plugin_get_document_data plugin_set_document_data 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.29 (Plugin API 228)
 */
void plugin_set_document_data_full (struct GeanyPlugin *plugin, struct GeanyDocument *doc, const gchar *key, gpointer data, GDestroyNotify free_func);



/**
 * project_write_config: 
 *
 * 
 * Forces the project file rewrite and emission of the project-save signal. 
 * 
 *         
 *
 * 
 * Plugins can use this function to save additional project data outside the project dialog.
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.25
 */
void project_write_config (void);



/**
 * sci_set_text: 
 * @sci:  Scintilla widget.
 * @text:  Text.
 *
 * 
 * Sets all text. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_set_text (ScintillaObject *sci, const gchar *text);



/**
 * sci_start_undo_action: 
 * @sci:  Scintilla GtkWidget.
 *
 * 
 * Begins grouping a set of edits together as one Undo action. 
 * 
 *         
 *
 * 
 * You must call sci_end_undo_action() after making your edits. 
 * 
 * 
 *         
 *
 */
void sci_start_undo_action (ScintillaObject *sci);



/**
 * sci_end_undo_action: 
 * @sci:  Scintilla GtkWidget.
 *
 * 
 * Ends grouping a set of edits together as one Undo action. 
 * 
 *         
 *
 * 
 * 
 * See sci_start_undo_action(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_end_undo_action (ScintillaObject *sci);



/**
 * sci_set_marker_at_line: 
 * @sci:  Scintilla widget.
 * @line_number:  Line number.
 * @marker:  Marker number.
 *
 * 
 * Sets a line marker. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_set_marker_at_line (ScintillaObject *sci, gint line_number, gint marker);



/**
 * sci_delete_marker_at_line: 
 * @sci:  Scintilla widget.
 * @line_number:  Line number.
 * @marker:  Marker number.
 *
 * 
 * Deletes a line marker. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_delete_marker_at_line (ScintillaObject *sci, gint line_number, gint marker);



/**
 * sci_is_marker_set_at_line: 
 * @sci:  Scintilla widget.
 * @line:  Line number.
 * @marker:  Marker number.
 *
 * 
 * Checks if a line has a marker set. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Whether it's set.
 */
gboolean sci_is_marker_set_at_line (ScintillaObject *sci, gint line, gint marker);



/**
 * sci_get_line_from_position: 
 * @sci:  Scintilla widget.
 * @position:  Position.
 *
 * 
 * Gets the line number from @position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The line.
 */
gint sci_get_line_from_position (ScintillaObject *sci, gint position);



/**
 * sci_get_col_from_position: 
 * @sci:  Scintilla widget.
 * @position:  Position.
 *
 * 
 * Gets the column number relative to the start of the line that @position is on. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The column.
 */
gint sci_get_col_from_position (ScintillaObject *sci, gint position);



/**
 * sci_get_position_from_line: 
 * @sci:  Scintilla widget.
 * @line:  Line.
 *
 * 
 * Gets the position for the start of @line. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Position.
 */
gint sci_get_position_from_line (ScintillaObject *sci, gint line);



/**
 * sci_get_current_position: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets the cursor position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Position.
 */
gint sci_get_current_position (ScintillaObject *sci);



/**
 * sci_set_current_position: 
 * @sci:  Scintilla widget.
 * @position:  Position.
 * @scroll_to_caret:  Whether to scroll the cursor in view.
 *
 * 
 * Sets the cursor position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_set_current_position (ScintillaObject *sci, gint position, gboolean scroll_to_caret);



/**
 * sci_get_line_count: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets the total number of lines. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The line count.
 */
gint sci_get_line_count (ScintillaObject *sci);



/**
 * sci_set_selection_start: 
 * @sci:  Scintilla widget.
 * @position:  Position.
 *
 * 
 * Sets the selection start position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_set_selection_start (ScintillaObject *sci, gint position);



/**
 * sci_set_selection_end: 
 * @sci:  Scintilla widget.
 * @position:  Position.
 *
 * 
 * Sets the selection end position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_set_selection_end (ScintillaObject *sci, gint position);



/**
 * sci_get_line_end_position: 
 * @sci:  Scintilla widget.
 * @line:  Line.
 *
 * 
 * Gets the position at the end of a line. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The position at the end of the line.
 */
gint sci_get_line_end_position (ScintillaObject *sci, gint line);



/**
 * sci_get_selection_start: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets the selection start position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Position.
 */
gint sci_get_selection_start (ScintillaObject *sci);



/**
 * sci_get_selection_end: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets the selection end position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Position.
 */
gint sci_get_selection_end (ScintillaObject *sci);



/**
 * sci_replace_sel: 
 * @sci:  Scintilla widget.
 * @text:  Text.
 *
 * 
 * Replaces selection. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_replace_sel (ScintillaObject *sci, const gchar *text);



/**
 * sci_get_length: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets the length of all text. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Length.
 */
gint sci_get_length (ScintillaObject *sci);



/**
 * sci_get_lexer: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets the currently used lexer. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The lexer ID
 */
gint sci_get_lexer (ScintillaObject *sci);



/**
 * sci_get_line_length: 
 * @sci:  Scintilla widget.
 * @line:  Line number.
 *
 * 
 * Gets line length. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Length.
 */
gint sci_get_line_length (ScintillaObject *sci, gint line);



/**
 * sci_get_line: 
 * @sci:  Scintilla widget.
 * @line_num:  Line number.
 *
 * 
 * Gets line contents. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A NULL-terminated copy of the line text.
 */
gchar* sci_get_line (ScintillaObject *sci, gint line_num);



/**
 * sci_get_text: 
 * @sci:  Scintilla widget.
 * @len:  Length of @text buffer, usually sci_get_length() + 1.
 * @text:  Text buffer; must be allocated @len + 1 bytes for null-termination.
 *
 * 
 * Gets all text. 
 * 
 *         
 *
 * 
 * Deprecated: sci_get_text is deprecated and should not be used in newly-written code. Use sci_get_contents() instead.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_get_text (ScintillaObject *sci, gint len, gchar *text);



/**
 * sci_get_contents: 
 * @sci:  Scintilla widget.
 * @buffer_len:  Buffer length to allocate, including the terminating null char, e.g. sci_get_length() + 1. Alternatively use -1 to get all text (since Geany 1.23).
 *
 * 
 * Allocates and fills a buffer with text from the start of the document. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A copy of the text. Should be freed when no longer needed.
 *
 * Since: 1.23 (0.17)
 */
gchar* sci_get_contents (ScintillaObject *sci, gint buffer_len);



/**
 * sci_get_selected_text: 
 * @sci:  Scintilla widget.
 * @text:  Text buffer; must be allocated sci_get_selected_text_length() + 1 bytes for null-termination.
 *
 * 
 * Gets selected text. 
 * 
 *         
 *
 * 
 * Deprecated: sci_get_selected_text is deprecated and should not be used in newly-written code. Use sci_get_selection_contents() instead.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_get_selected_text (ScintillaObject *sci, gchar *text);



/**
 * sci_get_selection_contents: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets selected text. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The selected text. Should be freed when no longer needed.
 *
 * Since: 0.17
 */
gchar* sci_get_selection_contents (ScintillaObject *sci);



/**
 * sci_get_selected_text_length: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets selected text length. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Length.
 */
gint sci_get_selected_text_length (ScintillaObject *sci);



/**
 * sci_get_line_is_visible: 
 * @sci:  Scintilla widget.
 * @line:  Line number.
 *
 * 
 * Checks if a line is visible (folding may have hidden it). 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Whether @line will be drawn on the screen.
 */
gboolean sci_get_line_is_visible (ScintillaObject *sci, gint line);



/**
 * sci_ensure_line_is_visible: 
 * @sci:  Scintilla widget.
 * @line:  Line number.
 *
 * 
 * Makes @line visible (folding may have hidden it). 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_ensure_line_is_visible (ScintillaObject *sci, gint line);



/**
 * sci_get_tab_width: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets display tab width (this is not indent width, see GeanyIndentPrefs). 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Width.
 *
 * Since: 0.15
 */
gint sci_get_tab_width (ScintillaObject *sci);



/**
 * sci_get_char_at: 
 * @sci:  Scintilla widget.
 * @pos:  Position.
 *
 * 
 * Gets a character. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Char.
 */
gchar sci_get_char_at (ScintillaObject *sci, gint pos);



/**
 * sci_has_selection: 
 * @sci:  Scintilla widget.
 *
 * 
 * Checks if there's a selection. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Whether a selection is present.
 *
 * Since: 0.15
 */
gboolean sci_has_selection (ScintillaObject *sci);



/**
 * sci_scroll_caret: 
 * @sci:  Scintilla widget.
 *
 * 
 * Scrolls the cursor in view. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_scroll_caret (ScintillaObject *sci);



/**
 * sci_find_text: 
 * @sci:  Scintilla widget.
 * @flags:  Bitmask of Scintilla search flags (SCFIND_*, see Scintilla documentation).
 * @ttf:  Pointer to a TextToFind structure which contains the text to find and the range.
 *
 * 
 * Finds text in the document. 
 * 
 *         
 *
 * 
 * The @ttf argument should be a pointer to a Sci_TextToFind structure which contains the text to find and the range in which the text should be searched.
 * 
 * Please refer to the Scintilla documentation for a more detailed description.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The position of the start of the found text if it succeeds, otherwise -1. The chrgText.cpMin and chrgText.cpMax members of TextToFind are filled in with the start and end positions of the found text.
 */
gint sci_find_text (ScintillaObject *sci, gint flags, struct Sci_TextToFind *ttf);



/**
 * sci_set_font: 
 * @sci:  Scintilla widget.
 * @style:  The style.
 * @font:  The font name.
 * @size:  The font size.
 *
 * 
 * Sets the font for a particular style. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_set_font (ScintillaObject *sci, gint style, const gchar *font, gint size);



/**
 * sci_goto_line: 
 * @sci:  Scintilla widget.
 * @line:  Line.
 * @unfold:  Whether to unfold first.
 *
 * 
 * Jumps to the specified line in the document. 
 * 
 *         
 *
 * 
 * If @unfold is set and @line is hidden by a fold, it is unfolded first to ensure it is visible. 
 * 
 * 
 *         
 *
 */
void sci_goto_line (ScintillaObject *sci, gint line, gboolean unfold);



/**
 * sci_get_style_at: 
 * @sci:  Scintilla widget.
 * @position:  Position.
 *
 * 
 * Gets style ID at @position. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Style ID.
 */
gint sci_get_style_at (ScintillaObject *sci, gint position);



/**
 * sci_get_text_range: 
 * @sci:  Scintilla widget.
 * @start:  Start.
 * @end:  End.
 * @text:  Text will be zero terminated and must be allocated (end - start + 1) bytes.
 *
 * 
 * Gets text between @start and @end. 
 * 
 *         
 *
 * 
 * Deprecated: sci_get_text_range is deprecated and should not be used in newly-written code. Use sci_get_contents_range() instead.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_get_text_range (ScintillaObject *sci, gint start, gint end, gchar *text);



/**
 * sci_get_contents_range: 
 * @sci:  Scintilla widget.
 * @start:  Start position.
 * @end:  End position.
 *
 * 
 * Gets text between @start and @end. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The text inside the given range. Should be freed when no longer needed.
 *
 * Since: 0.17
 */
gchar* sci_get_contents_range (ScintillaObject *sci, gint start, gint end);



/**
 * sci_insert_text: 
 * @sci:  Scintilla widget.
 * @pos:  Position, or -1 for current.
 * @text:  Text.
 *
 * 
 * Inserts text. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_insert_text (ScintillaObject *sci, gint pos, const gchar *text);



/**
 * sci_send_command: 
 * @sci:  The Scintilla GtkWidget.
 * @cmd:  SCI_COMMAND.
 *
 * 
 * Sends Scintilla commands without any parameters. 
 * 
 *         
 *
 * 
 * 
 * See http://scintilla.org for the documentation.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void sci_send_command (ScintillaObject *sci, gint cmd);



/**
 * sci_get_current_line: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets current line number. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Line number.
 */
gint sci_get_current_line (ScintillaObject *sci);



/**
 * sci_indicator_set: 
 * @sci:  Scintilla widget.
 * @indic:  The indicator number to set.
 *
 * 
 * Sets the current indicator. 
 * 
 *         
 *
 * 
 * This is necessary to define an indicator for a range of text or clearing indicators for a range of text.
 * 
 * 
 * See sci_indicator_clear
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void sci_indicator_set (ScintillaObject *sci, gint indic);



/**
 * sci_indicator_clear: 
 * @sci:  Scintilla widget.
 * @pos:  Starting position.
 * @len:  Length.
 *
 * 
 * Clears the currently set indicator from a range of text. 
 * 
 *         
 *
 * 
 * Starting at @pos, @len characters long. In order to make this function properly, you need to set the current indicator before with sci_indicator_set().
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void sci_indicator_clear (ScintillaObject *sci, gint pos, gint len);



/**
 * sci_find_matching_brace: 
 * @sci:  Scintilla widget.
 * @pos:  Position.
 *
 * 
 * Finds a matching brace at @pos. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Matching brace position.
 *
 * Since: 0.15
 */
gint sci_find_matching_brace (ScintillaObject *sci, gint pos);



/**
 * sci_get_selection_mode: 
 * @sci:  Scintilla widget.
 *
 * 
 * Gets selection mode. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Selection mode.
 */
gint sci_get_selection_mode (ScintillaObject *sci);



/**
 * sci_set_selection_mode: 
 * @sci:  Scintilla widget.
 * @mode:  Mode.
 *
 * 
 * Sets selection mode. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void sci_set_selection_mode (ScintillaObject *sci, gint mode);



/**
 * sci_set_line_indentation: 
 * @sci:  Scintilla widget.
 * @line:  Line to indent.
 * @indent:  Indentation width.
 *
 * 
 * Sets the indentation of a line. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.19
 */
void sci_set_line_indentation (ScintillaObject *sci, gint line, gint indent);



/**
 * sci_get_line_indentation: 
 * @sci:  Scintilla widget.
 * @line:  Line to get the indentation from.
 *
 * 
 * Gets the indentation width of a line. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Indentation width.
 *
 * Since: 0.19
 */
gint sci_get_line_indentation (ScintillaObject *sci, gint line);



/**
 * search_show_find_in_files_dialog: 
 * @dir:  The directory to search in (UTF-8 encoding). May be %NULL to determine it the usual way by using the current document's path.
 *
 * 
 * Shows the Find in Files dialog. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.14, plugin API 53
 */
void search_show_find_in_files_dialog (const gchar *dir);



/**
 * spawn_check_command: 
 * @command_line:  the command line to check.
 * @execute:  whether to check if the command line is really executable.
 * @error:  return location for error.
 *
 * 
 * Checks whether a command line is valid. 
 * 
 *         
 *
 * 
 * Checks if @command_line is syntactically valid.
 * 
 * All OS:
 * 
 *  - any leading spaces, tabs and new lines are skipped
 * 
 *  - an empty command is invalid
 * 
 * 
 * 
 * 
 * Unix:
 * 
 *  - the standard shell quoting and escaping rules are used, see g_shell_parse_argv() 
 * 
 *  - as a consequence, an unqouted # at the start of an argument comments to the end of line
 * 
 * 
 * 
 * 
 * Windows:
 * 
 *  - leading carriage returns are skipped too
 * 
 *  - a quoted program name must be entirely inside the quotes. No "C:\Foo\Bar".pdf or "C:\Foo\Bar".bat, which would be executed by Windows as C:\Foo\Bar.exe
 * 
 *  - an unquoted program name may not contain spaces. Foo Bar Qux will not be considered "Foo Bar.exe" Qux or "Foo Bar Qux.exe", depending on what executables exist, as Windows normally does.
 * 
 *  - the program name must be separated from the arguments by at least one space or tab
 * 
 *  - the standard Windows quoting and escaping rules are used: double quote is escaped with backslash, and any literal backslashes before a double quote must be duplicated.
 * 
 * 
 * 
 * 
 * If @execute is TRUE, also checks, using g_find_program_in_path(), if the program specified in @command_line exists and is executable.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE on success, %FALSE on error.
 *
 * Since: 1.25
 */
gboolean spawn_check_command (const gchar *command_line, gboolean execute, GError **error);



/**
 * spawn_kill_process: 
 * @pid:  id of the process to kill.
 * @error:  return location for error.
 *
 * 
 * Kills a process. 
 * 
 *         
 *
 * 
 * 
 * On Unix, sends a SIGTERM to the process.
 * 
 * On Windows, terminates the process with exit code 255 (used sometimes as "generic" error code, or for programs terminated with Ctrl+C / Ctrl+Break).
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE on success, %FALSE on error.
 *
 * Since: 1.25
 */
gboolean spawn_kill_process (GPid pid, GError **error);



/**
 * spawn_async: 
 * @working_directory: (nullable):  child's current working directory, or %NULL.
 * @command_line: (nullable):  child program and arguments, or %NULL.
 * @argv: (nullable):  child's argument vector, or %NULL.
 * @envp: (nullable):  child's environment, or %NULL.
 * @child_pid: (out) (optional):  return location for child process ID, or %NULL.
 * @error:  return location for error.
 *
 * 
 * Executes a child asynchronously. 
 * 
 *         
 *
 * 
 * A command line or an argument vector must be passed. If both are present, the argument vector is appended to the command line. An empty command line is not allowed.
 * 
 * If a @child_pid is passed, it's your responsibility to invoke g_spawn_close_pid().
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE on success, %FALSE on error.
 *
 * Since: 1.25
 */
gboolean spawn_async (const gchar *working_directory, const gchar *command_line, gchar **argv, gchar **envp, GPid *child_pid, GError **error);



/**
 * spawn_with_callbacks: (skip): 
 * @working_directory: (nullable):  child's current working directory, or %NULL.
 * @command_line: (nullable):  child program and arguments, or %NULL.
 * @argv: (nullable):  child's argument vector, or %NULL.
 * @envp: (nullable):  child's environment, or %NULL.
 * @spawn_flags:  flags from SpawnFlags.
 * @stdin_cb: (nullable):  callback to send data to childs's stdin, or %NULL.
 * @stdin_data:  data to pass to @stdin_cb.
 * @stdout_cb: (nullable):  callback to receive child's stdout, or %NULL.
 * @stdout_data:  data to pass to @stdout_cb.
 * @stdout_max_length:  maximum data length to pass to stdout_cb, 0 = default.
 * @stderr_cb: (nullable):  callback to receive child's stderr, or %NULL.
 * @stderr_data:  data to pass to @stderr_cb.
 * @stderr_max_length:  maximum data length to pass to stderr_cb, 0 = default.
 * @exit_cb: (nullable):  callback to invoke when the child exits, or %NULL.
 * @exit_data:  data to pass to @exit_cb.
 * @child_pid: (out) (optional):  return location for child process ID, or %NULL.
 * @error:  return location for error.
 *
 * 
 *   Executes a child program and setups callbacks. 
 * 
 *         
 *
 * 
 * A command line or an argument vector must be passed. If both are present, the argument vector is appended to the command line. An empty command line is not allowed.
 * 
 * The synchronous execution may not be combined with recursive callbacks.
 * 
 * In line buffered mode, the child input is broken on \n, \r\n, \r, \0 and max length.
 * 
 * All I/O callbacks are guaranteed to be invoked at least once with G_IO_ERR, G_IO_HUP or G_IO_NVAL set (except for a @stdin_cb which returns %FALSE before that). For the non-recursive callbacks, this is guaranteed to be the last call, and may be used to free any resources associated with the callback.
 * 
 * The @stdin_cb may write to channel only once per invocation, only if G_IO_OUT is set, and only a non-zero number of characters.
 * 
 * stdout_cb and stderr_cb may modify the received strings in any way, but must not free them.
 * 
 * The default max lengths are 24K for line buffered stdout, 8K for line buffered stderr, 4K for unbuffered input under Unix, and 2K for unbuffered input under Windows.
 * 
 * Due to a bug in some glib versions, the sources for recursive stdout/stderr callbacks may be converted from child watch to timeout(50ms). No callback changes are required.
 * 
 * exit_cb is always invoked last, after all I/O callbacks.
 * 
 * The @child_pid will be closed automatically, after @exit_cb is invoked.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE on success, %FALSE on error.
 *
 * Since: 1.25
 */
gboolean spawn_with_callbacks (const gchar *working_directory, const gchar *command_line, gchar **argv, gchar **envp, SpawnFlags spawn_flags, GIOFunc stdin_cb, gpointer stdin_data, SpawnReadFunc stdout_cb, gpointer stdout_data, gsize stdout_max_length, SpawnReadFunc stderr_cb, gpointer stderr_data, gsize stderr_max_length, GChildWatchFunc exit_cb, gpointer exit_data, GPid *child_pid, GError **error);



/**
 * spawn_write_data: 
 * @channel:  the channel to write data to.
 * @condition:  condition to check for G_IO_OUT.
 * @data:  SpawnWriteData to write to @channel.
 *
 * 
 * Writes (a portion of) the data pointed by @data->ptr to the @channel. 
 * 
 *         
 *
 * 
 * If G_IO_OUT in @condition is set, and the @data->size is > 0, attempts to write @data->ptr (or a portion of it, depending on the size) to the @channel. On success, increases ptr and decreases size with the number of characters written.
 * 
 * This function may converted to GIOFunc and passed to spawn_with_callbacks() as stdin_cb, together with a SpawnWriteData for stdin_data. As with any other callback data, make sure that stdin_data exists while the child is being executed. (For example, on asynchronous execution, you can allocate the data in the heap, and free it in your spawn_with_callbacks() exit_cb callback.)
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if the remaining size is > 0 and @condition does not indicate any error, %FALSE otherwise.
 *
 * Since: 1.25
 */
gboolean spawn_write_data (GIOChannel *channel, GIOCondition condition, SpawnWriteData *data);



/**
 * spawn_sync: 
 * @working_directory: (nullable):  child's current working directory, or %NULL.
 * @command_line: (nullable):  child program and arguments, or %NULL.
 * @argv: (nullable):  child's argument vector, or %NULL.
 * @envp: (nullable):  child's environment, or %NULL.
 * @stdin_data: (nullable):  data to send to childs's stdin, or %NULL.
 * @stdout_data: (nullable):  GString location to receive the child's stdout, or %NULL.
 * @stderr_data: (nullable):  GString location to receive the child's stderr, or %NULL.
 * @exit_status: (out) (optional):  return location for the child exit code, or %NULL.
 * @error:  return location for error.
 *
 * 
 * Executes a child synchronously. 
 * 
 *         
 *
 * 
 * A command line or an argument vector must be passed. If both are present, the argument vector is appended to the command line. An empty command line is not allowed.
 * 
 * The @stdin_data is sent to the child with spawn_write_data().
 * 
 * All output from the child, including the nul characters, is stored in @stdout_data and @stderr_data (if non-NULL). Any existing data in these strings will be erased.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE on success, %FALSE on error.
 *
 * Since: 1.25
 */
gboolean spawn_sync (const gchar *working_directory, const gchar *command_line, gchar **argv, gchar **envp, SpawnWriteData *stdin_data, GString *stdout_data, GString *stderr_data, gint *exit_status, GError **error);



/**
 * stash_group_load_from_key_file: 
 * @group:  .
 * @keyfile:  Usually loaded from a configuration file first.
 *
 * 
 * Reads key values from @keyfile into the group settings. 
 * 
 *         
 *
 * 
 * You should still call this even if the keyfile couldn't be loaded from disk so that all Stash settings are initialized to defaults. 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_load_from_key_file (StashGroup *group, GKeyFile *keyfile);



/**
 * stash_group_save_to_key_file: 
 * @group:  .
 * @keyfile:  .
 *
 * 
 * Writes group settings into key values in @keyfile. 
 * 
 *         
 *
 * 
 * @keyfile is usually written to a configuration file afterwards. 
 * 
 * 
 *         
 *
 */
void stash_group_save_to_key_file (StashGroup *group, GKeyFile *keyfile);



/**
 * stash_group_load_from_file: 
 * @group:  .
 * @filename:  Filename of the file to read, in locale encoding.
 *
 * 
 * Reads group settings from a configuration file using GKeyFile. 
 * 
 *         
 *
 * 
 * Stash settings will be initialized to defaults if the keyfile couldn't be loaded from disk. 
 * 
 * 
 * 
 * 
 * 
 * See stash_group_load_from_key_file(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if a key file could be loaded.
 */
gboolean stash_group_load_from_file (StashGroup *group, const gchar *filename);



/**
 * stash_group_save_to_file: 
 * @group:  .
 * @filename:  Filename of the file to write, in locale encoding.
 * @flags:  Keyfile options - G_KEY_FILE_NONE is the most efficient.
 *
 * 
 * Writes group settings to a configuration file using GKeyFile. 
 * 
 *         
 *
 * 
 * 
 * 
 * See stash_group_save_to_key_file(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  0 if the file was successfully written, otherwise the errno of the failed operation is returned.
 */
gint stash_group_save_to_file (StashGroup *group, const gchar *filename, GKeyFileFlags flags);



/**
 * stash_group_new: 
 * @name:  Name used for GKeyFile group.
 *
 * 
 * Creates a new group. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Group.
 */
StashGroup* stash_group_new (const gchar *name);



/**
 * stash_group_free_settings: 
 * @group:  .
 *
 * 
 * Frees the memory allocated for setting values in a group. 
 * 
 *         
 *
 * 
 * Useful e.g. to avoid freeing strings individually. This is @not called by stash_group_free(). 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_free_settings (StashGroup *group);



/**
 * stash_group_free: 
 * @group:  .
 *
 * 
 * Frees a group. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_free (StashGroup *group);



/**
 * stash_group_get_type: 
 *
 * 
 * Gets the GBoxed-derived GType for StashGroup. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  StashGroup type .
 */
GType stash_group_get_type (void);



/**
 * stash_group_add_boolean: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 *
 * 
 * Adds boolean setting. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_boolean (StashGroup *group, gboolean *setting, const gchar *key_name, gboolean default_value);



/**
 * stash_group_add_integer: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 *
 * 
 * Adds integer setting. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_integer (StashGroup *group, gint *setting, const gchar *key_name, gint default_value);



/**
 * stash_group_add_string: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value: (nullable):  String to copy if the key doesn't exist when loading, or %NULL.
 *
 * 
 * Adds string setting. 
 * 
 *         
 *
 * 
 * The contents of @setting will be initialized to %NULL. 
 * 
 * 
 *         
 *
 */
void stash_group_add_string (StashGroup *group, gchar **setting, const gchar *key_name, const gchar *default_value);



/**
 * stash_group_add_string_vector: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Vector to copy if the key doesn't exist when loading. Usually %NULL.
 *
 * 
 * Adds string vector setting (array of strings). 
 * 
 *         
 *
 * 
 * The contents of @setting will be initialized to %NULL. 
 * 
 * 
 *         
 *
 */
void stash_group_add_string_vector (StashGroup *group, gchar ***setting, const gchar *key_name, const gchar **default_value);



/**
 * stash_group_display: 
 * @group:  .
 * @owner:  If non-NULL, used to lookup widgets by name, otherwise widget pointers are assumed.
 *
 * 
 * Applies Stash settings to widgets, usually called before displaying the widgets. 
 * 
 *         
 *
 * 
 * The @owner argument depends on which type you use for StashWidgetID. 
 * See stash_group_update(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_display (StashGroup *group, GtkWidget *owner);



/**
 * stash_group_update: 
 * @group:  .
 * @owner:  If non-NULL, used to lookup widgets by name, otherwise widget pointers are assumed.
 *
 * 
 * Applies widget values to Stash settings, usually called after displaying the widgets. 
 * 
 *         
 *
 * 
 * The @owner argument depends on which type you use for StashWidgetID. 
 * See stash_group_display(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_update (StashGroup *group, GtkWidget *owner);



/**
 * stash_group_add_toggle_button: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 * @widget_id:  GtkWidget pointer or string to lookup widget later.
 *
 * 
 * Adds a GtkToggleButton (or GtkCheckButton) widget pref. 
 * 
 *         
 *
 * 
 * 
 * See stash_group_add_radio_buttons(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_toggle_button (StashGroup *group, gboolean *setting, const gchar *key_name, gboolean default_value, StashWidgetID widget_id);



/**
 * stash_group_add_radio_buttons: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 * @widget_id:  GtkWidget pointer or string to lookup widget later.
 * @enum_id:  Enum value for @widget_id.
 * @...:  pairs of @widget_id, @enum_id. Example (using widget lookup strings, but widget pointers can also work):  |[<!-- language="C" -->   enum {FOO, BAR};   stash_group_add_radio_buttons(group, &which_one_setting, "which_one", BAR,       "radio_foo", FOO, "radio_bar", BAR, NULL); ]|
 *
 * 
 * Adds a GtkRadioButton widget group pref. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_radio_buttons (StashGroup *group, gint *setting, const gchar *key_name, gint default_value, StashWidgetID widget_id, gint enum_id,...);



/**
 * stash_group_add_spin_button_integer: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 * @widget_id:  GtkWidget pointer or string to lookup widget later.
 *
 * 
 * Adds a GtkSpinButton widget pref. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_spin_button_integer (StashGroup *group, gint *setting, const gchar *key_name, gint default_value, StashWidgetID widget_id);



/**
 * stash_group_add_combo_box: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 * @widget_id:  GtkWidget pointer or string to lookup widget later.
 *
 * 
 * Adds a GtkComboBox widget pref. 
 * 
 *         
 *
 * 
 * 
 * See stash_group_add_combo_box_entry(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_combo_box (StashGroup *group, gint *setting, const gchar *key_name, gint default_value, StashWidgetID widget_id);



/**
 * stash_group_add_combo_box_entry: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 * @widget_id:  GtkWidget pointer or string to lookup widget later.
 *
 * 
 * Adds a GtkComboBoxEntry widget pref. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_combo_box_entry (StashGroup *group, gchar **setting, const gchar *key_name, const gchar *default_value, StashWidgetID widget_id);



/**
 * stash_group_add_entry: 
 * @group:  .
 * @setting:  Address of setting variable.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading.
 * @widget_id:  GtkWidget pointer or string to lookup widget later.
 *
 * 
 * Adds a GtkEntry widget pref. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_entry (StashGroup *group, gchar **setting, const gchar *key_name, const gchar *default_value, StashWidgetID widget_id);



/**
 * stash_group_add_widget_property: 
 * @group:  .
 * @setting:  Address of e.g. an integer if using an integer property.
 * @key_name:  Name for key in a GKeyFile.
 * @default_value:  Value to use if the key doesn't exist when loading. Should be cast into a pointer e.g. with GINT_TO_POINTER().
 * @widget_id:  GtkWidget pointer or string to lookup widget later.
 * @property_name:  .
 * @type:  can be 0 if passing a GtkWidget as the @widget_id argument to look it up from the GObject data.
 *
 * 
 * Adds a widget's read/write property to the stash group. 
 * 
 *         
 *
 * 
 * The property will be set when calling stash_group_display(), and read when calling stash_group_update(). 
 * Currently only string GValue properties will be freed before setting; patch for other types - see handle_widget_property(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void stash_group_add_widget_property (StashGroup *group, gpointer setting, const gchar *key_name, gpointer default_value, StashWidgetID widget_id, const gchar *property_name, GType type);



/**
 * symbols_get_context_separator: 
 * @ft_id:  File type identifier.
 *
 * 
 * Gets the context separator used by the tag manager for a particular file type. 
 * 
 *         
 *
 * 
 * 
 * 
 * Returns non-printing sequence "\x03" ie ETX (end of text) for filetypes without a context separator.
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The context separator string.
 *
 * Since: 0.19
 */
const gchar* symbols_get_context_separator (gint ft_id);



/**
 * tm_get_real_path: 
 * @file_name:  The original file_name
 *
 * 
 * Given a file name, returns a newly allocated string containing the realpath() of the file. 
 * 
 *         
 *
 * 
 * 
 * 
 * Deprecated: since 1.32 (ABI 235) 
 * 
 * See utils_get_real_path() 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A newly allocated string containing the real path to the file. NULL if none is available.
 */
gchar* tm_get_real_path (const gchar *file_name);



/**
 * tm_source_file_new: 
 * @file_name:  The file name.
 * @name:  Name of the used programming language, NULL to disable parsing.
 *
 * 
 * Initializes a TMSourceFile structure and returns a pointer to it. 
 * 
 *         
 *
 * 
 * The TMSourceFile has to be added to TMWorkspace to start its parsing. 
 * 
 * 
 * 
 *         
 *
 * Returns:  The created unparsed TMSourceFile object.
 */
TMSourceFile* tm_source_file_new (const char *file_name, const char *name);



/**
 * tm_source_file_free: 
 * @source_file:  The source file to free.
 *
 * 
 * Decrements the reference count of @source_file. 
 * 
 *         
 *
 * 
 * If the reference count drops to 0, then @source_file is freed, including all contents. Make sure the @source_file is already removed from any TMWorkSpace before the this happens. 
 * See tm_workspace_remove_source_file() 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 */
void tm_source_file_free (TMSourceFile *source_file);



/**
 * tm_source_file_get_type: 
 *
 * 
 * Gets the GBoxed-derived GType for TMSourceFile. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  TMSourceFile type .
 */
GType tm_source_file_get_type (void);



/**
 * tm_tag_get_type: 
 *
 * 
 * Gets the GType for a TMTag. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  TMTag type
 *
 * Since: 1.32 (API 233)
 */
GType tm_tag_get_type (void);



/**
 * tm_workspace_add_source_file: 
 * @source_file:  The source file to add to the workspace.
 *
 * 
 * Adds a source file to the workspace, parses it and updates the workspace tags. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void tm_workspace_add_source_file (TMSourceFile *source_file);



/**
 * tm_workspace_remove_source_file: 
 * @source_file:  Pointer to the source file to be removed.
 *
 * 
 * Removes a source file from the workspace if it exists. 
 * 
 *         
 *
 * 
 * This function also removes the tags belonging to this file from the workspace. To completely free the TMSourceFile pointer call tm_source_file_free() on it. 
 * 
 * 
 *         
 *
 */
void tm_workspace_remove_source_file (TMSourceFile *source_file);



/**
 * tm_workspace_add_source_files: 
 * @source_files: (element-type TMSourceFile):  The source files to be added to the workspace.
 *
 * 
 * Adds multiple source files to the workspace and updates the workspace tag arrays. 
 * 
 *         
 *
 * 
 * This is more efficient than calling tm_workspace_add_source_file() and tm_workspace_update_source_file() separately for each of the files. 
 * 
 * 
 *         
 *
 */
void tm_workspace_add_source_files (GPtrArray *source_files);



/**
 * tm_workspace_remove_source_files: 
 * @source_files: (element-type TMSourceFile):  The source files to be removed from the workspace.
 *
 * 
 * Removes multiple source files from the workspace and updates the workspace tag arrays. 
 * 
 *         
 *
 * 
 * This is more efficient than calling tm_workspace_remove_source_file() separately for each of the files. To completely free the TMSourceFile pointers call tm_source_file_free() on each of them. 
 * 
 * 
 *         
 *
 */
void tm_workspace_remove_source_files (GPtrArray *source_files);



/**
 * ui_set_statusbar: 
 * @log:  Whether the message should be recorded in the Status window.
 * @format:  A printf -style string.
 *
 * 
 * Displays text on the statusbar. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void ui_set_statusbar (gboolean log, const gchar *format,...);



/**
 * ui_add_document_sensitive: 
 * @widget:  The widget to add.
 *
 * 
 * Adds a widget to the list of widgets that should be set sensitive/insensitive when some documents are present/no documents are open. 
 * 
 *         
 *
 * 
 * It will be removed when the widget is destroyed. 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.15
 */
void ui_add_document_sensitive (GtkWidget *widget);



/**
 * ui_frame_new_with_alignment: 
 * @label_text:  The label text.
 * @alignment:  An address to store the alignment widget pointer.
 *
 * 
 * Creates a GNOME HIG-style frame (with no border and indented child alignment). 
 * 
 *         
 *
 * 
 * 
 * 
 * Deprecated: 1.29: Use GTK API directly 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer floating):  The frame widget, setting the alignment container for packing child widgets.
 */
GtkWidget* ui_frame_new_with_alignment (const gchar *label_text, GtkWidget **alignment);



/**
 * ui_dialog_vbox_new: 
 * @dialog:  The parent container for the GtkVBox.
 *
 * 
 * Makes a fixed border for dialogs without increasing the button box border. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  The packed GtkVBox.
 */
GtkWidget* ui_dialog_vbox_new (GtkDialog *dialog);



/**
 * ui_button_new_with_image: 
 * @stock_id:  A GTK_STOCK_NAME string.
 * @text:  Button label text, can include mnemonics.
 *
 * 
 * Creates a GtkButton with custom text and a stock image similar to gtk_button_new_from_stock(). 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer floating):  The new GtkButton.
 */
GtkWidget* ui_button_new_with_image (const gchar *stock_id, const gchar *text);



/**
 * ui_image_menu_item_new: 
 * @stock_id:  Stock image ID, e.g. GTK_STOCK_OPEN.
 * @label:  Menu item label, can include mnemonics.
 *
 * 
 * Creates a GtkImageMenuItem with a stock image and a custom label. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer floating):  The new GtkImageMenuItem.
 *
 * Since: 0.16
 */
GtkWidget* ui_image_menu_item_new (const gchar *stock_id, const gchar *label);



/**
 * ui_entry_add_clear_icon: 
 * @entry:  The GtkEntry object to which the icon should be attached.
 *
 * 
 * Adds a small clear icon to the right end of the passed @entry. 
 * 
 *         
 *
 * 
 * A callback to clear the contents of the GtkEntry is automatically added.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void ui_entry_add_clear_icon (GtkEntry *entry);



/**
 * ui_combo_box_add_to_history: 
 * @combo_entry:  .
 * @text: (nullable):  Text to add, or %NULL for current entry text.
 * @history_len:  Max number of items, or 0 for default.
 *
 * 
 * Prepends @text to the drop down list, removing a duplicate element in the list if found. 
 * 
 *         
 *
 * 
 * Also ensures there are <= @history_len elements. 
 * 
 * 
 *         
 *
 */
void ui_combo_box_add_to_history (GtkComboBoxText *combo_entry, const gchar *text, gint history_len);



/**
 * ui_tree_view_set_tooltip_text_column: 
 * @tree_view:  The tree view
 * @column:  The column to get the tooltip from
 *
 * 
 * Adds text tooltips to a tree view. 
 * 
 *         
 *
 * 
 * This is similar to gtk_tree_view_set_tooltip_column() but considers the column contents to be text, not markup -- it uses gtk_tooltip_set_text() rather than gtk_tooltip_set_markup() to set the tooltip's value.
 * 
 * Unlike gtk_tree_view_set_tooltip_column() you currently cannot change or remove the tooltip column after it has been added. Trying to do so will probably give funky results.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 1.25 (API 223)
 */
void ui_tree_view_set_tooltip_text_column (GtkTreeView *tree_view, gint column);



/**
 * ui_widget_modify_font_from_string: 
 * @widget:  The widget.
 * @str:  The font name as expected by pango_font_description_from_string().
 *
 * 
 * Modifies the font of a widget using gtk_widget_modify_font(). 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 */
void ui_widget_modify_font_from_string (GtkWidget *widget, const gchar *str);



/**
 * ui_path_box_new: 
 * @title: (nullable):  The file chooser dialog title, or %NULL.
 * @action:  The mode of the file chooser.
 * @entry:  Can be an unpacked GtkEntry, or the child of an unpacked widget, such as GtkComboBoxEntry.
 *
 * 
 * Creates a GtkHBox with @entry packed into it and an open button which runs a file chooser, replacing entry text (if successful) with the path returned from the GtkFileChooser. 
 * 
 *         
 *
 * 
 * @entry can be the child of an unparented widget, such as GtkComboBoxEntry. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer floating):  The GtkHBox.
 */
GtkWidget* ui_path_box_new (const gchar *title, GtkFileChooserAction action, GtkEntry *entry);



/**
 * ui_table_add_row: 
 * @table:  
 * @row:  The row number of the table.
 *
 * 
 * Packs all GtkWidgets passed after the row argument into a table, using one widget per cell. 
 * 
 *         
 *
 * 
 * The first widget is not expanded as the table grows, as this is usually a label. 
 * 
 * 
 *         
 *
 */
void ui_table_add_row (GtkTable *table, gint row,...);



/**
 * ui_widget_set_tooltip_text: 
 * @widget:  The widget the tooltip should be set for.
 * @text:  The text for the tooltip.
 *
 * 
 * Sets @text as the contents of the tooltip for @widget. 
 * 
 *         
 *
 * 
 * 
 * 
 * Deprecated: 0.21 use gtk_widget_set_tooltip_text() instead 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void ui_widget_set_tooltip_text (GtkWidget *widget, const gchar *text);



/**
 * ui_lookup_widget: 
 * @widget:  Widget with the @widget_name property set.
 * @widget_name:  Name to lookup.
 *
 * 
 * Returns a widget from a name in a component, usually created by Glade. 
 * 
 *         
 *
 * 
 * Call it with the toplevel widget in the component (i.e. a window/dialog), or alternatively any widget in the component, and the name of the widget you want returned. 
 * 
 * See ui_hookup_widget().
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer none):  The widget found.
 *
 * Since: 0.16
 */
GtkWidget* ui_lookup_widget (GtkWidget *widget, const gchar *widget_name);



/**
 * ui_progress_bar_start: 
 * @text: (nullable):  The text to be shown as the progress bar label or %NULL to leave it empty.
 *
 * 
 * Starts a constantly pulsing progressbar in the right corner of the statusbar (if the statusbar is visible). 
 * 
 *         
 *
 * 
 * This is a convenience function which adds a timer to pulse the progressbar constantly until ui_progress_bar_stop() is called. You can use this function when you have time consuming asynchronous operation and want to display some activity in the GUI and when you don't know about detailed progress steps. The progressbar widget is hidden by default when it is not active. This function and ui_progress_bar_stop() will show and hide it automatically for you.
 * 
 * You can also access the progressbar widget directly using geany->main_widgets->progressbar and use the GtkProgressBar API to set discrete fractions to display better progress information. In this case, you need to show and hide the widget yourself. You can find some example code in src/printing.c.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void ui_progress_bar_start (const gchar *text);



/**
 * ui_progress_bar_stop: 
 *
 * 
 * Stops a running progress bar and hides the widget again. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void ui_progress_bar_stop (void);



/**
 * ui_menu_add_document_items: (skip): 
 * @menu:  Menu.
 * @active: (nullable):  Which document to highlight, or %NULL.
 * @callback:  is used for each menu item's "activate" signal and will be passed the corresponding document pointer as user_data.
 *
 * 
 *   Adds a list of document items to @menu. 
 * 
 *         
 *
 * 
 * 
 * You should check doc->is_valid in the callback. 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.19
 */
void ui_menu_add_document_items (GtkMenu *menu, GeanyDocument *active, GCallback callback);



/**
 * ui_menu_add_document_items_sorted: (skip): 
 * @menu:  Menu.
 * @active: (nullable):  Which document to highlight, or %NULL.
 * @callback:  is used for each menu item's "activate" signal and will be passed the corresponding document pointer as user_data.
 * @compare_func:  is used to sort the list. Might be %NULL to not sort the list.
 *
 * 
 *   Adds a list of document items to @menu. 
 * 
 *         
 *
 * 
 * @compare_func might be NULL to not sort the documents in the menu. In this case, the order of the document tabs is used.
 * 
 * See document_compare_by_display_name() for an example sort function.
 * 
 * 
 * You should check doc->is_valid in the callback. 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.21
 */
void ui_menu_add_document_items_sorted (GtkMenu *menu, GeanyDocument *active, GCallback callback, GCompareFunc compare_func);



/**
 * ui_is_keyval_enter_or_return: 
 * @keyval:  A keyval.
 *
 * 
 * Checks whether the passed @keyval is the Enter or Return key. 
 * 
 *         
 *
 * 
 * There are three different Enter/Return key values (GDK_Return, GDK_ISO_Enter, GDK_KP_Enter). This is just a convenience function. 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if @keyval is the one of the Enter/Return key values, otherwise %FALSE.
 *
 * Since: 0.19
 */
gboolean ui_is_keyval_enter_or_return (guint keyval);



/**
 * ui_get_gtk_settings_integer: 
 * @property_name:  The property to read.
 * @default_value:  The default value in case the value could not be read.
 *
 * 
 * Reads an integer from the GTK default settings registry (see http://library.gnome.org/devel/gtk/stable/GtkSettings.html). 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The value for the property if it exists, otherwise the @default_value.
 *
 * Since: 0.19
 */
gint ui_get_gtk_settings_integer (const gchar *property_name, gint default_value);



/**
 * ui_lookup_stock_label: 
 * @stock_id:  stock_id to lookup e.g. GTK_STOCK_OPEN.
 *
 * 
 * Finds the label text associated with stock_id. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The label text for stock
 *
 * Since: Geany 1.22
 */
const gchar* ui_lookup_stock_label (const gchar *stock_id);



/**
 * utils_open_browser: 
 * @uri:  The URI to open in the web browser.
 *
 * 
 * Tries to open the given URI in a browser. 
 * 
 *         
 *
 * 
 * On Windows, the system's default browser is opened. On non-Windows systems, the browser command set in the preferences dialog is used. In case that fails or it is unset, the user is asked to correct or fill it.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 *
 * Since: 0.16
 */
void utils_open_browser (const gchar *uri);



/**
 * utils_write_file: 
 * @filename:  The filename of the file to write, in locale encoding.
 * @text:  The text to write into the file.
 *
 * 
 * Writes @text into a file named @filename. 
 * 
 *         
 *
 * 
 * If the file doesn't exist, it will be created. If it already exists, it will be overwritten.
 * 
 * You should use g_file_set_contents() instead if you don't need file permissions and other metadata to be preserved, as that always handles disk exhaustion safely.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  0 if the file was successfully written, otherwise the errno of the failed operation is returned.
 */
gint utils_write_file (const gchar *filename, const gchar *text);



/**
 * utils_find_open_xml_tag: 
 * @sel:  .
 * @size:  .
 *
 * 
 * Searches backward through @size bytes looking for a '<'. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  The tag name (newly allocated) or %NULL if no opening tag was found.
 */
gchar* utils_find_open_xml_tag (const gchar sel[], gint size);



/**
 * utils_find_open_xml_tag_pos: 
 * @sel:  .
 * @size:  .
 *
 * 
 * Searches backward through @size bytes looking for a '<'. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (nullable):  pointer to '<' of the found opening tag within @sel, or %NULL if no opening tag was found.
 */
const gchar* utils_find_open_xml_tag_pos (const gchar sel[], gint size);



/**
 * utils_str_casecmp: 
 * @s1: (nullable):  Pointer to first string or %NULL.
 * @s2: (nullable):  Pointer to second string or %NULL.
 *
 * 
 * A replacement function for g_strncasecmp() to compare strings case-insensitive. 
 * 
 *         
 *
 * 
 * It converts both strings into lowercase using g_utf8_strdown() and then compare both strings using strcmp(). This is not completely accurate regarding locale-specific case sorting rules but seems to be a good compromise between correctness and performance.
 * 
 * The input strings should be in UTF-8 or locale encoding.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  an integer less than, equal to, or greater than zero if @s1 is found, respectively, to be less than, to match, or to be greater than @s2.
 *
 * Since: 0.16
 */
gint utils_str_casecmp (const gchar *s1, const gchar *s2);



/**
 * utils_str_middle_truncate: 
 * @string:  Input string.
 * @truncate_length:  The length in characters of the resulting string.
 *
 * 
 * Truncates the input string to a given length. 
 * 
 *         
 *
 * 
 * Characters are removed from the middle of the string, so the start and the end of string won't change.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A copy of @string which is truncated to @truncate_length characters, should be freed when no longer needed.
 *
 * Since: 0.17
 */
gchar* utils_str_middle_truncate (const gchar *string, guint truncate_length);



/**
 * utils_str_equal: 
 * @a: (nullable):  Pointer to first string or %NULL.
 * @b: (nullable):  Pointer to second string or %NULL.
 *
 * 
 * NULL-safe string comparison. 
 * 
 *         
 *
 * 
 * Returns %TRUE if both @a and @b are %NULL or if @a and @b refer to valid strings which are equal.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE if @a equals @b, else %FALSE.
 */
gboolean utils_str_equal (const gchar *a, const gchar *b);



/**
 * utils_remove_ext_from_filename: 
 * @filename:  The filename to operate on.
 *
 * 
 * Removes the extension from @filename and return the result in a newly allocated string. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A newly-allocated string, should be freed when no longer needed.
 */
gchar* utils_remove_ext_from_filename (const gchar *filename);



/**
 * utils_get_date_time: 
 * @format:  The format string to pass to strftime(3). See the strftime(3) documentation for details, in UTF-8 encoding.
 * @time_to_use: (nullable):  The date/time to use, in time_t format or %NULL to use the current time.
 *
 * 
 * Retrieves a formatted date/time string from strftime(). 
 * 
 *         
 *
 * 
 * This function should be preferred to directly calling strftime() since this function works on UTF-8 encoded strings.
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A newly-allocated string, should be freed when no longer needed.
 *
 * Since: 0.16
 */
gchar* utils_get_date_time (const gchar *format, time_t *time_to_use);



/**
 * utils_get_setting_integer: 
 * @config:  A GKeyFile object.
 * @section:  The group name to look in for the key.
 * @key:  The key to find.
 * @default_value:  The default value which will be returned when @section or @key don't exist.
 *
 * 
 * Wraps g_key_file_get_integer() to add a default value argument. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The value associated with @key as an integer, or the given default value if the value could not be retrieved.
 */
gint utils_get_setting_integer (GKeyFile *config, const gchar *section, const gchar *key, const gint default_value);



/**
 * utils_get_setting_boolean: 
 * @config:  A GKeyFile object.
 * @section:  The group name to look in for the key.
 * @key:  The key to find.
 * @default_value:  The default value which will be returned when section or key don't exist.
 *
 * 
 * Wraps g_key_file_get_boolean() to add a default value argument. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The value associated with @key as a boolean, or the given default value if the value could not be retrieved.
 */
gboolean utils_get_setting_boolean (GKeyFile *config, const gchar *section, const gchar *key, const gboolean default_value);



/**
 * utils_get_setting_string: 
 * @config:  A GKeyFile object.
 * @section:  The group name to look in for the key.
 * @key:  The key to find.
 * @default_value:  The default value which will be returned when @section or @key don't exist.
 *
 * 
 * Wraps g_key_file_get_string() to add a default value argument. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A newly allocated string, either the value for @key or a copy of the given default value if it could not be retrieved.
 */
gchar* utils_get_setting_string (GKeyFile *config, const gchar *section, const gchar *key, const gchar *default_value);



/**
 * utils_get_locale_from_utf8: 
 * @utf8_text:  UTF-8 encoded text.
 *
 * 
 * Converts the given UTF-8 encoded string into locale encoding. 
 * 
 *         
 *
 * 
 * On Windows platforms, it does nothing and instead it just returns a copy of the input string.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The converted string in locale encoding, or a copy of the input string if conversion failed. Should be freed with g_free(). If @utf8_text is %NULL, %NULL is returned.
 */
gchar* utils_get_locale_from_utf8 (const gchar *utf8_text);



/**
 * utils_get_utf8_from_locale: 
 * @locale_text:  Text in locale encoding.
 *
 * 
 * Converts the given string (in locale encoding) into UTF-8 encoding. 
 * 
 *         
 *
 * 
 * On Windows platforms, it does nothing and instead it just returns a copy of the input string.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  The converted string in UTF-8 encoding, or a copy of the input string if conversion failed. Should be freed with g_free(). If @locale_text is %NULL, %NULL is returned.
 */
gchar* utils_get_utf8_from_locale (const gchar *locale_text);



/**
 * utils_mkdir: 
 * @path:  The path of the directory to create, in locale encoding.
 * @create_parent_dirs:  Whether to create intermediate parent directories if necessary.
 *
 * 
 * Creates a directory if it doesn't already exist. 
 * 
 *         
 *
 * 
 * Creates intermediate parent directories as needed, too. The permissions of the created directory are set 0700.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  0 if the directory was successfully created, otherwise the errno of the failed operation is returned.
 */
gint utils_mkdir (const gchar *path, gboolean create_parent_dirs);



/**
 * utils_get_file_list_full: 
 * @path:  The path of the directory to scan, in locale encoding.
 * @full_path:  Whether to include the full path for each filename in the list. Obviously this will use more memory.
 * @sort:  Whether to sort alphabetically (UTF-8 safe).
 * @error:  The location for storing a possible error, or %NULL.
 *
 * 
 * Gets a list of files from the specified directory. 
 * 
 *         
 *
 * 
 * Locale encoding is expected for @path and used for the file list. The list and the data in the list should be freed after use, e.g.: 
 * |[<!-- language="C" -->
 *   g_slist_foreach(list, (GFunc) g_free, NULL);
 *   g_slist_free(list); 
 * ]|
 * 
 * If you don't need a list you should use the foreach_dir() macro instead - it's more efficient.
 * 
 * 
 * 
 * 
 * 
 * See utils_get_file_list(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (element-type filename) (transfer full) (nullable):  A newly allocated list or %NULL if no files were found. The list and its data should be freed when no longer needed.
 */
GSList* utils_get_file_list_full (const gchar *path, gboolean full_path, gboolean sort, GError **error);



/**
 * utils_get_file_list: 
 * @path:  The path of the directory to scan, in locale encoding.
 * @length:  The location to store the number of non-%NULL data items in the list, unless %NULL.
 * @error:  The location for storing a possible error, or %NULL.
 *
 * 
 * Gets a sorted list of files from the specified directory. 
 * 
 *         
 *
 * 
 * Locale encoding is expected for @path and used for the file list. The list and the data in the list should be freed after use, e.g.: 
 * |[<!-- language="C" -->
 *   g_slist_foreach(list, (GFunc) g_free, NULL);
 *   g_slist_free(list); 
 * ]|
 * 
 * 
 * 
 * See utils_get_file_list_full(). 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (element-type filename) (transfer full) (nullable):  A newly allocated list or %NULL if no files were found. The list and its data should be freed when no longer needed.
 */
GSList* utils_get_file_list (const gchar *path, guint *length, GError **error);



/**
 * utils_string_replace_all: 
 * @haystack:  The input string to operate on. This string is modified in place.
 * @needle:  The string which should be replaced.
 * @replace:  The replacement for @needle.
 *
 * 
 * Replaces all occurrences of @needle in @haystack with @replace. 
 * 
 *         
 *
 * 
 * As of Geany 0.16, @replace can match @needle, so the following will work: 
 * |[<!-- language="C" -->
 *   utils_string_replace_all(text, "\n", "\r\n"); 
 * ]|
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Number of replacements made.
 */
guint utils_string_replace_all (GString *haystack, const gchar *needle, const gchar *replace);



/**
 * utils_string_replace_first: 
 * @haystack:  The input string to operate on. This string is modified in place.
 * @needle:  The string which should be replaced.
 * @replace:  The replacement for @needle.
 *
 * 
 * Replaces only the first occurrence of @needle in @haystack with @replace. 
 * 
 *         
 *
 * 
 * For details, see utils_string_replace_all().
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  Number of replacements made.
 *
 * Since: 0.16
 */
guint utils_string_replace_first (GString *haystack, const gchar *needle, const gchar *replace);



/**
 * utils_spawn_sync: 
 * @dir: (nullable):  The child's current working directory, or %NULL to inherit parent's.
 * @argv:  The child's argument vector.
 * @env: (nullable):  The child's environment, or %NULL to inherit parent's.
 * @flags:  Ignored.
 * @child_setup: (skip):  Ignored.
 * @user_data: (skip):  Ignored.
 * @std_out: (out) (optional):  The return location for child output, or %NULL.
 * @std_err: (out) (optional):  The return location for child error messages, or %NULL.
 * @exit_status: (out) (optional):  The child exit status, as returned by waitpid(), or %NULL.
 * @error:  The return location for error or %NULL.
 *
 * 
 * Wraps spawn_sync(), which see. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE on success, %FALSE if an error was set.
 */
gboolean utils_spawn_sync (const gchar *dir, gchar **argv, gchar **env, GSpawnFlags flags, GSpawnChildSetupFunc child_setup, gpointer user_data, gchar **std_out, gchar **std_err, gint *exit_status, GError **error);



/**
 * utils_spawn_async: 
 * @dir: (nullable):  The child's current working directory, or %NULL to inherit parent's.
 * @argv:  The child's argument vector.
 * @env: (nullable):  The child's environment, or %NULL to inherit parent's.
 * @flags:  Ignored.
 * @child_setup: (skip):  Ignored.
 * @user_data:  Ignored.
 * @child_pid: (out) (nullable):  The return location for child process ID, or %NULL.
 * @error:  The return location for error or %NULL.
 *
 * 
 * Wraps spawn_async(), which see. 
 * 
 *         
 *
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  %TRUE on success, %FALSE if an error was set.
 */
gboolean utils_spawn_async (const gchar *dir, gchar **argv, gchar **env, GSpawnFlags flags, GSpawnChildSetupFunc child_setup, gpointer user_data, GPid *child_pid, GError **error);



/**
 * utils_str_remove_chars: 
 * @string:  String to search.
 * @chars:  Characters to remove.
 *
 * 
 * Removes characters from a string, in place. 
 * 
 *         
 *
 * 
 * 
 * 
 * See g_strdelimit. 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  @string - return value is only useful when nesting function calls, e.g.:  |[<!-- language="C" -->   str = utils_str_remove_chars(g_strdup("f_o_o"), "_");  ]|
 */
gchar* utils_str_remove_chars (gchar *string, const gchar *chars);



/**
 * utils_copy_environment: 
 * @exclude_vars:  NULL-terminated array of variable names to exclude.
 * @first_varname:  Name of the first variable to copy into the new array.
 * @...:  Key-value pairs of variable names and values, NULL-terminated.
 *
 * 
 * Copies the current environment into a new array. 
 * 
 *         
 *
 * 
 * @exclude_vars is a NULL-terminated array of variable names which should be not copied. All further arguments are key, value pairs of variables which should be added to the environment.
 * 
 * The argument list must be NULL-terminated.
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer full):  The new environment array. Use g_strfreev() to free it.
 */
gchar** utils_copy_environment (const gchar **exclude_vars, const gchar *first_varname,...);



/**
 * utils_strv_shorten_file_list: 
 * @file_names: (array length=file_names_len):  The list of strings to process.
 * @file_names_len:  The number of strings contained in @file_names. Can be -1 if it's terminated by %NULL.
 *
 * 
 * Transform file names in a list to be shorter. 
 * 
 *         
 *
 * 
 * This function takes a list of file names (probably with absolute paths), and transforms the paths such that they are short but still unique. This is intended for dialogs which present the file list to the user, where the base name may result in duplicates (showing the full path might be inappropriate).
 * 
 * The algorthm strips the common prefix (e-g. the user's home directory) and replaces the longest common substring with an ellipsis ("...").
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns: (transfer full):  A newly-allocated array of transformed paths strings, terminated by %NULL. Use g_strfreev() to free it.
 *
 * Since: 1.34 (API 239)
 */
gchar** utils_strv_shorten_file_list (gchar **file_names, gssize file_names_len);



/**
 * utils_get_real_path: 
 * @file_name:  The file name to get the real path of.
 *
 * 
 * Get a link-dereferenced, absolute version of a file name. 
 * 
 *         
 *
 * 
 * This is similar to the POSIX realpath function when passed a %NULL argument.
 * 
 * This function suffers the same problems as the POSIX function realpath(), namely that it's impossible to determine a suitable size for the returned buffer, and so it's limited to a maximum of PATH_MAX.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *         
 *
 * Returns:  A newly-allocated string containing the real path which should be freed with g_free() when no longer needed, or %NULL if the real path cannot be obtained.
 *
 * Since: 1.32 (API 235)
 */
gchar* utils_get_real_path (const gchar *file_name);

