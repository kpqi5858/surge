//-------------------------------------------------------------------------------------------------------
//
//	Shortcircuit
//
//	Copyright 2004 Claes Johanson
//
//-------------------------------------------------------------------------------------------------------
#pragma once

#include "vstgui/vstgui.h"

union rgbpixel
{
   struct
   {
      unsigned char b, g, r, a;
   } ch;
   unsigned int rgba;
};

class CDIBitmap
{
public:
   CDIBitmap(long width, long height);
   virtual ~CDIBitmap();

   void draw(VSTGUI::CDrawContext* pContext, VSTGUI::CRect& rect, const VSTGUI::CPoint& offset = VSTGUI::CPoint(0, 0));

   void clear(VSTGUI::CColor color);
   unsigned int ccol_to_int(VSTGUI::CColor col);
   VSTGUI::CColor int_to_ccol(unsigned int col);

   void clear(unsigned int color);

   void fillRect(VSTGUI::CRect r, unsigned int color);
   void setPixel(int x, int y, unsigned int color);

   inline int getWidth()
   {
      return _width;
   }
   inline int getHeight()
   {
      return _height;
   }

   void begin();
   void commit();

   int _width = 0, _height = 0;

protected:
private:
   VSTGUI::SharedPointer<VSTGUI::CBitmap> _bitmap;
   VSTGUI::SharedPointer<VSTGUI::CBitmapPixelAccess> _bitmapAccess;
};
