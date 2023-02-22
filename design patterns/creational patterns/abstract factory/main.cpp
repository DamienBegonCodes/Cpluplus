#include <abstract_factory.hpp>
#include <string>

int main()
{
    std::string os = "Win";
    GuiFactory* factory;
    if (os == "Mac") factory = new MacFactory();
    else if (os == "Win") factory = new WinFactory();

    auto my_button = factory->createButton();
    auto my_checkbox = factory->createCheckbox();

    my_button->paint();
    my_checkbox->paint();
}