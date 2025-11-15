#include "pch.h"
#include "DrawStats.h"

void DrawStats::Render(CanvasWrapper canvas, Session& session)
{

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
    Vector2 drawPos;
    drawPos.X = boxStart.X + 5;
    drawPos.Y = boxStart.Y + 5;

    // Render session details
	session.Render(canvas, drawPos, alphaText);

}