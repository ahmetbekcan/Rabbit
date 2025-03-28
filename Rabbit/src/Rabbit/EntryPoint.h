#pragma once

#ifdef RB_PLATFORM_WINDOWS
extern Rabbit::Application* Rabbit::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Rabbit::CreateApplication();
	app->Run();
	delete app;
}

#endif