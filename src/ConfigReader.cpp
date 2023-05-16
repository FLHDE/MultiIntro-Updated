#include "ConfigReader.h"

IntroConfig::IntroConfig()
    : randomIntroOnMenuVisit(true), introAmount(0)
{}

void ConfigReader::GetConfig(const std::string &path, IntroConfig& config)
{
    if (!ir.open(path.c_str(), false))
        return;

    while (ir.read_header())
    {
        if (!ir.is_header("Options"))
            continue;

        while (ir.read_value())
        {
            if (ir.is_value("random_intro_on_menu_visit"))
                config.randomIntroOnMenuVisit = ir.get_value_bool(0);

            if (ir.is_value("intro_amount"))
                config.introAmount = ir.get_value_int(0);
        }
    }

    ir.close();
}
