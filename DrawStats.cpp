#include "pch.h"
#include "DrawStats.h"

void DrawStats::Render(CanvasWrapper canvas, Session& session)
{
	// Store canvas reference
	this->canvas = &canvas;

    // Screen size
    float screenW = static_cast<float>(canvas.GetSize().X);
    float screenH = static_cast<float>(canvas.GetSize().Y);

    // Scoreboard parameters
    const float scoreboardRatio = 0.60f;
    float scoreboardWidth = scoreboardRatio * screenW;
    float scoreboardLeft = (screenW - scoreboardWidth) / 2.0f;
    float scoreboardRight = scoreboardLeft + scoreboardWidth;
    float scoreboardTop = screenH * 0.275f;

    // Box dimensions (relative to screen size)
    float boxWidth = screenW * 0.18f;
    float boxHeight = screenH * 0.45f;
    float boxGap = screenW * 0.01f;

    // Use int explicitly for Vector2
    Vector2 boxStart(static_cast<int>(scoreboardRight + boxGap),
        static_cast<int>(scoreboardTop));
    Vector2 boxEnd(static_cast<int>(boxStart.X + boxWidth),
        static_cast<int>(boxStart.Y + boxHeight));

    // Draw box
    canvas.SetColor(0, 0, 0, alphaBox);
    canvas.DrawRect(boxStart, boxEnd);

	// Setup initial draw position inside the box
    drawPos.X = boxStart.X + 5;
    drawPos.Y = boxStart.Y + 5;

    // Render session details
	session.Render(*this);

}

void DrawStats::DrawColorStringFloat(float flt, std::string text)
{
    SetColorByValueFloat(flt);
    canvas->SetPosition(drawPos);
    canvas->DrawString(text);
}

void DrawStats::DrawColorStringInt(int i, std::string text)
{
    SetColorByValueInt(i);
    canvas->SetPosition(drawPos);
    canvas->DrawString(text);
}


void DrawStats::DrawWhiteString(std::string text)
{
    canvas->SetColor(static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255), alphaText);
    canvas->SetPosition(drawPos);
    canvas->DrawString(text);
}

void DrawStats::SetColorByValueFloat(float flt)
{
    if (flt == 0) {
        canvas->SetColor(static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255), alphaText);
    }
    else if (flt < 0) {
        canvas->SetColor(static_cast<uint8_t>(255), 0, 0, alphaText);
    }
    else {
        canvas->SetColor(0, static_cast<uint8_t>(255), 0, alphaText);
    }
}

void DrawStats::SetColorByValueInt(int i)
{
    if (i == 0) {
        canvas->SetColor(static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255), alphaText);
    }
    else if (i < 0) {
        canvas->SetColor(static_cast<uint8_t>(255), 0, 0, alphaText);
    }
    else {
        canvas->SetColor(0, static_cast<uint8_t>(255), 0, alphaText);
    }
}
