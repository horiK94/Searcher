#include <Siv3D.hpp>
#include <vector>
#include "StateController.h"

void Main()
{
	Window::SetStyle(WindowStyle::Fixed);
	Window::ResizeVirtual(400, 400);
	Graphics::SetVSyncEnabled(true);

	StateController controller = StateController();

	while (System::Update())
	{
		controller.Update();
	}
}
