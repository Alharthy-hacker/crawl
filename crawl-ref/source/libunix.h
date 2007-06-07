#ifndef LIBUNIX_H
#define LIBUNIX_H


// Some replacement routines missing in gcc

#ifndef O_BINARY
#define O_BINARY O_RDWR
#endif

char getche(void);

void message_out(int mline, int colour, const char *str, int firstcol = 0,
                 bool newline = true);
void clear_message_window();

int get_number_of_lines();
int get_number_of_cols();

int getch_ck(void);
int clrscr(void);
int cprintf(const char *format,...);
int gotoxy(int x, int y);
void fakecursorxy(int x, int y);
int itoa(int value, char *strptr, int radix);
int kbhit(void);
int putch(unsigned char chr);
int putwch(unsigned chr);
int stricmp(const char *str1, const char *str2);
int translate_keypad(int keyin);
int wherex(void);
int wherey(void);
int window(int x1, int y1, int x2, int y2);
void update_screen(void);
void clear_to_end_of_line(void);
void clear_to_end_of_screen(void);
void get_input_line_from_curses( char *const buff, int len );

void delay(unsigned long time);
void unixcurses_shutdown(void);
void unixcurses_startup(void);
void textbackground(int bg);
void textcolor(int col);
void textattr(int col);

void set_altcharset(bool alt_on);
bool get_altcharset();

void set_cursor_enabled(bool enabled);
bool is_cursor_enabled();
inline void enable_smart_cursor(bool) { }
inline bool is_smart_cursor_enabled() { return (false); }

#ifndef _LIBUNIX_IMPLEMENTATION
/* Some stuff from curses, to remove compiling warnings.. */
extern "C"
{
    int getstr(char *);
    int getch(void);
    int noecho(void);
    int echo(void);
    char *strlwr(char *str);
}
#endif


#endif
