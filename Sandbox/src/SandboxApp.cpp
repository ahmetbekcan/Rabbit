#include <Rabbit.h>

class Sandbox : public Rabbit::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Rabbit::Application* Rabbit::CreateApplication()
{
	return new Sandbox();
}