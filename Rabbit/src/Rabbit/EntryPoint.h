#pragma once

#ifdef RB_PLATFORM_WINDOWS
extern Rabbit::Application* Rabbit::CreateApplication();

int main(int argc, char** argv)
{
	Rabbit::Log::Init();
	RB_CORE_WARN("WARN!");
	RB_INFO("INFO!");

	auto app = Rabbit::CreateApplication();
	app->Run();
	delete app;
}

#endif