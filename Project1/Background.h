#pragma once
class CBackground
{
public:
	CBackground();
	void OnDraw(Gdiplus::Graphics* graphics, double scrollX);
	double GetImageHeight() {return mImage->GetHeight(); };

private:
	Gdiplus::Bitmap* mImage;
};

