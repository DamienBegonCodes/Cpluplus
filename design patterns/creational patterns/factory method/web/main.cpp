#include <factory_method.hpp>
#include <iostream>
#include <memory>

int main()
{
    Dialog* dialog;
    std::string os = "web";

    if (os == "windows") dialog = new WindowsDialog();
    else if (os == "web") dialog = new HtmlDialog();

    dialog->render();
}
