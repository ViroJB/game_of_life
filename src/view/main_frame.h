#pragma once

#include <wx/wx.h>

#include "draw/draw_board_pane.h"

class MainFrame : public wxFrame {
   public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    wxMenu *getMenuSpeed();
    wxMenu *getMenuFigures();

   private:
      wxMenu *_menuSpeed;
      wxMenu *_menuFigures;
      wxMenu *_menuSimulation;
};