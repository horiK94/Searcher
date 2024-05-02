#include <Siv3D.hpp>
#include <vector>
#include "StateController.h"

void Main()
{
	Window::SetStyle(WindowStyle::Fixed);
	Window::ResizeVirtual(400, 400);

	StateController controller = StateController();

	while (System::Update())
	{
		controller.Update();
	}

	//Window::SetStyle(WindowStyle::Sizable);
	Graphics::SetVSyncEnabled(true);
	while (System::Update())
	{
		ClearPrint();
		Print << U"frameBufferSize: " << Window::GetState().frameBufferSize;
		Print << U"virtualSize: " << Window::GetState().virtualSize;
		Print << U"scene size: " << Scene::Size();
		Print << U"get pos" << Window::GetPos();
		Print << Profiler::FPS() << U" FPS";

		// 100px サイズの市松模様
		Vec2 leftUpperSize = Vec2{ 100 - Window::GetPos().x % 100, 100 - Window::GetPos().y % 100 };
		int baseX = Window::GetPos().x / 100;
		int baseY = Window::GetPos().y / 100;

		for (int32 y = 0; y < 50; ++y)
		{
			for (int32 x = 0; x < 50; ++x)
			{
				Rect rect = { };
				if (x == 0)
				{
					rect.x = 0;
					rect.w = leftUpperSize.x;
				}
				else
				{
					rect.x = leftUpperSize.x + (x - 1) * 100;
					rect.w = 100;
				}

				if (y == 0)
				{
					rect.y = 0;
					rect.h = leftUpperSize.y;
				}
				else
				{
					rect.y = leftUpperSize.y + (y - 1) * 100;
					rect.h = 100;
				}

				if ((baseX + x + baseY + y) % 2)
				{
					rect.draw(ColorF{ 0.2, 0.3, 0.4 });
				}
			}
		}
	}
}
