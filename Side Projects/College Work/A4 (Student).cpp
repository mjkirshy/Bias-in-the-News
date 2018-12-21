/**
 * a4.cpp
 * Name: Ryan Smith
 * Person number: 50067030
 *
 * All definitions of functions required for A4 are contained in here.
 * Feel free to add more function definitions to this, but you must
 * include at least the required functions.
 *
 * You may only use the following headers:
 *    <algorithm>, <cstring>, <string>, <vector>, <list>, <stack>,
 *    <queue>, <sstream>, "Tag.hpp"
 */

#include "Tag.hpp"
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <sstream>

// helper functions //

std::string lowerIt(std::string& file) {
    std::string lowerFile = file;
    for (int i = 0; i < lowerFile.length(); ++i) {
        if (lowerFile[i] != ' ' || lowerFile[i] != '<' || lowerFile[i] != '>') {
            lowerFile[i] = _tolower(lowerFile[i]);
        }
    }
    return lowerFile;
}

std::string cleanIt(std::string& file) {

    std::string before = file;
    std::string cleanedFile;

    for (int i = 0; i < before.length(); ++i) {
        if (before[i] != ' ') {
            cleanedFile += before[i];
        }
        else {
//            if (i == 0 && before[i] != '<') {
//            }
//            else
            if (before.back() == '<') {
                cleanedFile += before[i];
            }
            else if (before[i + 1] == ' ') {

            }
            else if (before[i + 1] != ' ') {
                cleanedFile += before[i];
            }
        }
    }
    return cleanedFile;
}

bool tagValid(std::string& file) {

    // contains all the if statements to check JUST tag validity, not order or anything else //
    std::string before = file, check;
    size_t lineBreakCheck = before.find("\n");

    // removes line breaks from inside tags //
    if (lineBreakCheck != std::string::npos) {
        if ((lineBreakCheck + 1) != 'n') {
            check = before.substr(0, (lineBreakCheck));
            check += " ";
            check += before.substr(lineBreakCheck + 2);
        }
        check = cleanIt(check);
    }
    else {
        check = before;
    }

    if (check.compare("<!doctype html>") == 0 || check.compare("<!doctype html >") == 0) {
        return true;
    }
    else if (check.compare("<html>") == 0 || check.compare("<html >") == 0) {
        return true;
    }
    else if (check.compare("</html>") == 0 || check.compare("</html >") == 0) {
        return true;
    }
    else if (check.compare("<head>") == 0 || check.compare("<head >") == 0) {
        return true;
    }
    else if (check.compare("</head>") == 0 || check.compare("</head >") == 0) {
        return true;
    }
    else if (check.compare("<title>") == 0 || check.compare("<title >") == 0) {
        return true;
    }
    else if (check.compare("<body>") == 0 || check.compare("<body >") == 0) {
        return true;
    }
    else if (check.compare("</body>") == 0 || check.compare("</body >") == 0) {
        return true;
    }
    else if (check.compare("<p>") == 0 || check.compare("<p >") == 0) {
        return true;
    }
    else if (check.compare("</p>") == 0 || check.compare("</p >") == 0) {
        return true;
    }
    else if (check.compare("<br>") == 0 || check.compare("<br />") == 0 || check.compare("<br/>") == 0 ||
             check.compare("<br >") == 0) {
        return true;
    }
    else if (check.compare("<div>") == 0 || check.compare("<div >") == 0) {
        return true;
    }
    else if (check.compare("</div>") == 0 || check.compare("</div >") == 0) {
        return true;
    }
    else if (check.compare("<span>") == 0 || check.compare("<span >") == 0) {
        return true;
    }
    else if (check.compare("</span>") == 0 || check.compare("</span >") == 0) {
        return true;
    }
    return false;
}

std::string lineBreak(std::string& file) {

    // contains all the if statements to check JUST tag validity, not order or anything else //
    std::string before = file, check;
    size_t lineBreakCheck = before.find("\n");

    // removes line breaks from inside tags //
    if (lineBreakCheck != std::string::npos) {
        if ((lineBreakCheck + 1) != 'n') {
            check = before.substr(0, (lineBreakCheck));
            check += " ";
            check += before.substr(lineBreakCheck + 2);
        }
        check = cleanIt(check);
    }
    else {
        check = before;
    }

    if (check.compare("<!doctype html>") == 0 || check.compare("<!doctype html >") == 0) {
        return check;
    }
    else if (check.compare("<html>") == 0 || check.compare("<html >") == 0) {
        return check;
    }
    else if (check.compare("</html>") == 0 || check.compare("</html >") == 0) {
        return check;
    }
    else if (check.compare("<head>") == 0 || check.compare("<head >") == 0) {
        return check;
    }
    else if (check.compare("</head>") == 0 || check.compare("</head >") == 0) {
        return check;
    }
    else if (check.compare("<title>") == 0 || check.compare("<title >") == 0) {
        return check;
    }
    else if (check.compare("<body>") == 0 || check.compare("<body >") == 0) {
        return check;
    }
    else if (check.compare("</body>") == 0 || check.compare("</body >") == 0) {
        return check;
    }
    else if (check.compare("<p>") == 0 || check.compare("<p >") == 0) {
        return check;
    }
    else if (check.compare("</p>") == 0 || check.compare("</p >") == 0) {
        return check;
    }
    else if (check.compare("<br>") == 0 || check.compare("<br />") == 0 || check.compare("<br/>") == 0 ||
             check.compare("<br >") == 0) {
        return check;
    }
    else if (check.compare("<div>") == 0 || check.compare("<div >") == 0) {
        return check;
    }
    else if (check.compare("</div>") == 0 || check.compare("</div >") == 0) {
        return check;
    }
    else if (check.compare("<span>") == 0 || check.compare("<span >") == 0) {
        return check;
    }
    else if (check.compare("</span>") == 0 || check.compare("</span >") == 0) {
        return check;
    }
    return "0";
}

bool titleValid(std::string& file) {

    std::string check = file, closeCheck = file, temp;
    size_t begin = 0, end = 0, secondBeg = 0, secondEnd = 0;
    begin = check.find('>'), end = check.find('<', (begin));
    check = check.substr(begin + 1, (end - begin) - 1);
    check = cleanIt(check);
    secondBeg = closeCheck.find('<', (begin + 1)), secondEnd = closeCheck.find('>', (secondBeg));
    if (secondBeg == std::string::npos && secondEnd == std::string::npos) {
        return true;
    }
    else if (secondBeg == std::string::npos && secondEnd != std::string::npos) {
        return false;
    }
    else if (secondBeg != std::string::npos && secondEnd == std::string::npos) {
        return false;
    }
    else {
        closeCheck = closeCheck.substr((secondBeg), (secondEnd));
        for (int i = 0; i < check.length(); ++i) {
            if (check[i] == ' ' && check.length() < 2) {
                return false;
            }
            else {
                temp += check[i];
            }
        }
        // after erasing, if title text is not empty return true.
        if (!temp.empty()) {
            if (closeCheck.compare("</title>") == 0 || closeCheck.compare("</title >") == 0) {
                return true;
            }

        }
    }
    return false;
}

std::string idCheck(std::string& file) {

    std::string temp = file, id, tag;
    bool loopCond = true;

    size_t equal = temp.find("=");
    size_t idee = temp.find("id");

    size_t beginQ = temp.find('"');
    size_t endQ = temp.find('"', beginQ + 1);

    size_t beginI = temp.find("<");
    size_t endI = temp.find(">", beginI + 1);

    tag = temp.substr(beginI, (endI - beginI) + 1);
    id = temp.substr(beginQ, (endQ - beginQ));

    if (equal < beginQ && beginQ != std::string::npos && endQ != std::string::npos) {
        for (int i = 0; i < id.length(); ++i) {
            if (id[i] == ' ') {
                return "0";
            }
        }
        tag = temp.erase(idee, (endQ - idee) + 1);
    }
    return cleanIt(tag);
}

std::string tagGrab(std::string& file) {

    std::string tagger = file, temp;
    bool loopCond = true;
    tagger = cleanIt(tagger);
    size_t begin = 0, end = 0, equal = 0;

    while (loopCond == true) {
        if (tagger.find_first_of('<') < tagger.find_first_of('>')) {
            begin = tagger.find('<', begin), end = tagger.find('>', (end + 1));
            if (begin == std::string::npos && end == std::string::npos) {
                loopCond = false;
            }
            else {
                temp = tagger.substr((begin), (end - begin) + 1);
                equal = temp.find("=");
                if (equal != std::string::npos) {
                    temp = idCheck(temp);
                    if (temp == "0") {
                        return "0";
                    }
                }
            }
            // make the id check and erase here before the valid tag part //
            if (tagValid(temp) == true) {
                if (temp.compare("<title>") == 0 || temp.compare("<title >") == 0) {
                    end = tagger.find('>', end + 1);
                    temp = tagger.substr((begin), (end - begin) + 1);
                    if (!titleValid(temp)) {
                        return "0";
                    }
                }

            }
            else {
                return "0";
            }
            begin = end;
        }
        else {
            return "0";
        }
    }

    return tagger;
}

Tag* traverseTree(Tag* root, std::string& id) {

    Tag* temp = nullptr;

    if (root == nullptr) {
        return temp;
    }
    if (root->_id == id) {
        return root;
    }
    if (!root->_children.empty()) {
        for (int childIndex = 0; childIndex < root->_children.size(); ++childIndex) {
            if (traverseTree(root->_children.at(childIndex), id) != nullptr) {
                temp = traverseTree(root->_children.at(childIndex), id);
                break;
            }
        }
    }
    return temp;
}

bool searchVisible(Tag* const root) {

    bool temp = false;

    if (root == nullptr) {
        return true;
    }
    if (root->_name == "content" || root->_name == "title") {
        root->_displayed = true;
        temp = true;
    }
    if (!root->_children.empty()) {
        for (int childIndex = 0; childIndex < root->_children.size(); ++childIndex) {
            if (searchVisible(root->_children.at(childIndex)) != true) {
                root->_displayed = true;
                temp = true;
            }
        }
    }
    return temp;
}

// autograder function checks //

bool html_is_valid(const std::string& document) {
    std::string validCheck = document, holder;
    size_t begin = 0, end = 0, idee = 0;
    validCheck = lowerIt(validCheck);
    validCheck = tagGrab(validCheck);
    bool loopCond = true;
    if (validCheck == "0") {
        return false;
    }
    std::stack<std::string> tagHolder, stackHtml, stackHead, stackBody, stackTitle, stackDoctype;
    while (loopCond == true) {
        begin = validCheck.find('<', begin);
        end = validCheck.find('>', begin);
        if (begin == std::string::npos && end == std::string::npos) {
            break;
        }
        holder = validCheck.substr(begin, (end - begin) + 1);
        // if there is an id within a tag, check it//
        if ((idee = holder.find("id") != std::string::npos)) {
            size_t secondID = holder.find("id", idee+1);
            if(secondID == std::string::npos){
                return false;
            }
            holder = idCheck(holder);
            if (tagValid(holder) != true) {
                return false;
            }
        }
        // check for a line break inside the tag //
        if (size_t lineBreakCheck = holder.find("\n") != std::string::npos) {
            holder = lineBreak(holder);
            if (holder == "0") {
                return false;
            }
        }
        // begin all tag and order checks //
        if (holder == "<!doctype html>" || holder == "<!doctype html >") {
            if (tagHolder.empty()) {
                if (begin == validCheck.find_first_of('<') && end == validCheck.find_first_of('>')) {
                    tagHolder.push(holder);
                    stackDoctype.push(holder);
                    begin = end;
                }
            }
            else {
                return false;
            }
        }
        else if (holder == "<br>" || holder == "<br />" || holder == "<br/>" || holder == "<br >") {
            if (tagHolder.top() == "<head>" || tagHolder.top() == "<head >") {
                return false;
            }
            begin = end;
        }
        else if ((holder == "<html>" || holder == "<html >")) {
            tagHolder.push(holder);
            stackHtml.push(holder);
            if (stackHtml.size() > 1) {
                return false;
            }
            begin = end;
        }
        else if ((holder == "</html>" || holder == "</html >") && (tagHolder.top() == "<html>" || tagHolder.top() == "<html >")) {
            tagHolder.pop();
            loopCond = false;
        }
        else if ((holder == "<head>" || holder == "<head >") && (tagHolder.top() == "<html>" || tagHolder.top() == "<html >")) {
            tagHolder.push(holder);
            stackHead.push(holder);
            if (stackHead.size() > 1) {
                return false;
            }
            begin = end;
        }
        else if ((holder == "</head>" || holder == "</head >") && (tagHolder.top() == "<head>" || tagHolder.top() == "<head >")) {
            tagHolder.pop();
            begin = end;
        }
        else if ((holder == "<title>" || holder == "<title >") && (tagHolder.top() == "<head>" || tagHolder.top() == "<head >")) {
            begin = end;
            stackTitle.push(holder);
            if (stackTitle.size() > 1) {
                return false;
            }
        }
        else if ((holder == "</title>" || holder == "</title >") && (tagHolder.top() == "<head>" || tagHolder.top() == "<head >")) {
            begin = end;
        }
        else if ((holder == "<body>" || holder == "<body >") && (tagHolder.top() == "<html>" || tagHolder.top() == "<html >")) {
            size_t headCheck = validCheck.find("<head>", end + 1);
            if (headCheck == std::string::npos) {
                tagHolder.push(holder);
                begin = end;
                stackBody.push(holder);
                if (stackBody.size() > 1) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else if ((holder == "</body>" || holder == "</body >") && (tagHolder.top() == "<body>" || tagHolder.top() == "<body >")) {
            tagHolder.pop();
            begin = end;
        }
        else if (holder == "<span>" || holder == "<span >") {
            if (tagHolder.top() == "<head>" || tagHolder.top() == "<head >" || tagHolder.top() == "<span>" || tagHolder.top() == "<span >") {
                return false;
            }
            tagHolder.push(holder);
            begin = end;
        }
        else if (holder == "</span>" || holder == "</span >") {
            tagHolder.pop();
            begin = end;
        }
        else if (holder == "<p>" || holder == "<p >") {
            if (tagHolder.top() == "<body>" || tagHolder.top() == "<body >" || tagHolder.top() == "<div>" || tagHolder.top() == "<div >") {
                tagHolder.push(holder);
                begin = end;
            }
            else {
                return false;
            }

        }
        else if ((holder == "</p>" || "</p >") && (tagHolder.top() == "<p>" || tagHolder.top() == "<p >")) {
            tagHolder.pop();
            begin = end;
        }
        else if (holder == "<div>" || holder == "<div >") {
            if (tagHolder.top() == "<body>" || tagHolder.top() == "<body >" || tagHolder.top() == "<p>" || tagHolder.top() == "<p >" || tagHolder.top() == "<div>" || tagHolder.top() == "<div >") {
                tagHolder.push(holder);
                begin = end;
            }
            else {
                return false;
            }
        }
        else if ((holder == "</div>" || holder == "</div >") && (tagHolder.top() == "<div>" || tagHolder.top() == "<div >")) {
            tagHolder.pop();
            begin = end;
        }
        else {
            return false;
        }
    }
    if (stackDoctype.empty() || tagHolder.size() > 1) {
        return false;
    }
    if (stackTitle.empty()) {
        return false;
    }
    return true;
}

Tag* generate_DOM_tree(const std::string& document) {


    return nullptr;
}

void determine_visible_objects(Tag* const root) {

    if (root == nullptr) {
        return;
    }
    if (!root->_children.empty()) {
        for (int childIndex = 0; childIndex < root->_children.size(); ++childIndex) {
            determine_visible_objects(root->_children[childIndex]);
            if (root->_children[childIndex]->_displayed == true) {
                root->_displayed = true;
            }
        }
    }
    if (root->_name == "content" || root->_name == "title") {
        root->_displayed = true;
    }
}

std::string print_visible_elements(Tag* const root) {
    // TODO: Finish this function.
    return "";
}

Tag* getElementByID(Tag* const root, const std::string& id) {

    Tag* getter = nullptr;
    std::string ideee = id;

    if (root == nullptr) {
        return getter;
    }
    else if (root->_id == ideee) {
        return root;
    }
    else if (!root->_children.empty()) {
        for (int childIndex = 0; childIndex < root->_children.size(); ++childIndex) {
            if (traverseTree(root->_children.at(childIndex), ideee) != nullptr) {
                getter = traverseTree(root->_children.at(childIndex), ideee);
            }
        }
    }
    return getter;
}