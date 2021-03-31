/*
 * Automatically generated file - do not edit
 */

#include "gtkcompat.h"
#include "Scintilla.h"
#include "ScintillaWidget.h"


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

