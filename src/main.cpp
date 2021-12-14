#include "ColorOut.h"
#include <iostream>

int main() {
    Zain::ColorOut clout;

    clout.bold().print("This is a bold text.\n");
    clout.faint().print("This is a faint text.\n");
    clout.underline().print("This is an underlined text.\n");
    clout.underline().bold().print("This is an underlined bold text.\n");
    clout.foreground().red().print("This is a red text.\n");
    clout.foreground().blue().background().red()
        .print("This is a red text with red background.\n");
    clout.bold().background().blue().foreground().black()
        .print("This is a bold text in blue background.\n");

    clout.foreground().yellow()
        .print("This is a combined text. It has ");
    clout.underline().foreground().yellow()
        .print("underlined text,");
    std::cout << ' ';
    clout.bold().foreground().yellow()
        .print("bold text, ");
    clout.foreground().yellow().background().black()
        .print("and black background text.\n");

    return 0;
}