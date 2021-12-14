#ifndef COLOROUT_H
#define COLOROUT_H

#include <sstream>
#include <string>

namespace Zain {
    class ColorOut {
    private:
        bool isSettingBackground;
        bool isSettingForeground;
        bool isNewLineTrimmed;
        std::string styleCode;
        short foregroundCode;
        short backgroundCode;
        std::stringstream stringStream;

        bool isStyleCodeSupplied();
        bool isForegroundCodeSupplied();
        bool isBackgroundCodeSupplied();
        bool isLastCharacterNewLine(const std::string &text);
        void appendStyleCodeIfExists();
        void appendForegroundCodeIfExists();
        void appendBackgroundCodeIfExists();
        void appendText(const std::string &text);
        void appendNewLineIfWasTrimmed();
        void createSequence(const std::string &text);

    public:
        ColorOut();
        Zain::ColorOut& foreground();
        Zain::ColorOut& background();
        Zain::ColorOut& bold();
        Zain::ColorOut& faint();
        Zain::ColorOut& italic();
        Zain::ColorOut& underline();
        Zain::ColorOut& black();
        Zain::ColorOut& red();
        Zain::ColorOut& green();
        Zain::ColorOut& yellow();
        Zain::ColorOut& blue();
        Zain::ColorOut& magenta();
        Zain::ColorOut& cyan();
        Zain::ColorOut& white();
        Zain::ColorOut& brightBlack();
        Zain::ColorOut& brightRed();
        Zain::ColorOut& brightGreen();
        Zain::ColorOut& brightYellow();
        Zain::ColorOut& brightBlue();
        Zain::ColorOut& brightMagenta();
        Zain::ColorOut& brightCyan();
        Zain::ColorOut& brightWhite();
        Zain::ColorOut& print(const std::string &text);
    };
}

#endif