#include "ColorOut.h"

#include <iostream>
#include <string>

bool Zain::ColorOut::isStyleCodeSupplied() {
    if (styleCode.length() == 0) {
        return false;
    }
    return true;
}

bool Zain::ColorOut::isForegroundCodeSupplied() {
    if (foregroundCode == -1) {
        return false;
    }
    return true;
}

bool Zain::ColorOut::isBackgroundCodeSupplied() {
    if (backgroundCode == -1) {
        return false;
    }
    return true;
}

bool Zain::ColorOut::isLastCharacterNewLine(const std::string &text) {
    if (text.substr(text.length() - 1) == "\n") {
        return true;
    }
    return false;
}

void Zain::ColorOut::appendStyleCodeIfExists() {
    if (isStyleCodeSupplied()) {
        stringStream << styleCode;
    }
}

void Zain::ColorOut::appendForegroundCodeIfExists() {
    if (isForegroundCodeSupplied() && isStyleCodeSupplied()) {
        stringStream << ';' << foregroundCode;
    } else if (isForegroundCodeSupplied()) {
        stringStream << foregroundCode;
    }
}

void Zain::ColorOut::appendBackgroundCodeIfExists() {
    if ((isBackgroundCodeSupplied() && isForegroundCodeSupplied())
        || (isBackgroundCodeSupplied() && isStyleCodeSupplied())) {
        stringStream << ';' << backgroundCode;
    } else if (isBackgroundCodeSupplied()) {
        stringStream << backgroundCode;
    }
}

void Zain::ColorOut::appendText(const std::string &text) {
    if (isLastCharacterNewLine(text)) {
        stringStream << text.substr(0, text.length() - 1);
        isNewLineTrimmed = true;
    } else {
        stringStream << text;
    }
}

void Zain::ColorOut::appendNewLineIfWasTrimmed() {
    if (isNewLineTrimmed) {
        stringStream << '\n';
    }
}

void Zain::ColorOut::createSequence(const std::string &text) {
    stringStream << "\033[";
    appendStyleCodeIfExists();
    appendForegroundCodeIfExists();
    appendBackgroundCodeIfExists();
    stringStream << 'm';
    appendText(text);
    stringStream << "\033[0m";
    appendNewLineIfWasTrimmed();
}

Zain::ColorOut::ColorOut() {
    styleCode = std::string();
    foregroundCode = -1;
    backgroundCode = -1;
    isSettingForeground = false;
    isSettingBackground = false;
    isNewLineTrimmed = false;
}

Zain::ColorOut& Zain::ColorOut::foreground() {
    isSettingForeground = true;
    return *this;
}

Zain::ColorOut& Zain::ColorOut::background() {
    isSettingBackground = true;
    return *this;
}

Zain::ColorOut& Zain::ColorOut::bold() {
    if(styleCode.length() == 0) {
        styleCode.append("1");
    } else {
        styleCode.append(";1");
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::faint() {
    if(styleCode.length() == 0) {
        styleCode.append("2");
    } else {
        styleCode.append(";2");
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::italic() {
    if(styleCode.length() == 0) {
        styleCode.append("3");
    } else {
        styleCode.append(";3");
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::underline() {
    if(styleCode.length() == 0) {
        styleCode.append("4");
    } else {
        styleCode.append(";4");
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::black() {
    if (isSettingForeground) {
        foregroundCode = 30;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 40;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::red() {
    if (isSettingForeground) {
        foregroundCode = 31;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 41;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::green() {
    if (isSettingForeground) {
        foregroundCode = 32;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 42;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::yellow() {
    if (isSettingForeground) {
        foregroundCode = 33;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 43;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::blue() {
    if (isSettingForeground) {
        foregroundCode = 34;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 44;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::magenta() {
    if (isSettingForeground) {
        foregroundCode = 35;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 45;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::cyan() {
    if (isSettingForeground) {
        foregroundCode = 36;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 46;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::white() {
    if (isSettingForeground) {
        foregroundCode = 37;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 47;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightBlack() {
    if (isSettingForeground) {
        foregroundCode = 90;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 100;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightRed() {
    if (isSettingForeground) {
        foregroundCode = 91;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 101;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightGreen() {
    if (isSettingForeground) {
        foregroundCode = 92;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 102;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightYellow() {
    if (isSettingForeground) {
        foregroundCode = 93;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 103;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightBlue() {
    if (isSettingForeground) {
        foregroundCode = 94;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 104;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightMagenta() {
    if (isSettingForeground) {
        foregroundCode = 95;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 105;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightCyan() {
    if (isSettingForeground) {
        foregroundCode = 96;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 106;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::brightWhite() {
    if (isSettingForeground) {
        foregroundCode = 97;
        isSettingForeground = false;
    } else if (isSettingBackground) {
        backgroundCode = 107;
        isSettingBackground = false;
    }
    return *this;
}

Zain::ColorOut& Zain::ColorOut::print(const std::string &text) {
    createSequence(text);
    std::cout << stringStream.str();
    stringStream.str(std::string());
    styleCode = std::string();
    foregroundCode = -1;
    backgroundCode = -1;
    isNewLineTrimmed = false;
    return *this;
}