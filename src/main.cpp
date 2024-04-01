// #include <iomanip>  // Add missing include statement for iomanip
// #include <iostream>
// #include <locale>  // Add missing include statement for locale
// #include <string>
// #include <thread>
// #include <vector>

// #include <wx/wx.h>
// // #include "wx/wx.h"

// // class Bla : public wxPanel {
// //    public:
// //     Bla(wxFrame* parent);
// //     void OnPaint(wxPaintEvent& event);

// //    private:
// //     wxFrame* parent;
// // };

// // Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// // Any live cell with two or three live neighbors lives on to the next generation.
// // Any live cell with more than three live neighbors dies, as if by overpopulation.
// // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

// void printGrid(std::vector<std::vector<wchar_t>> grid, wchar_t fillChar) {
//     for (int i = 0; i < grid.size(); i++) {
//         for (int j = 0; j < grid[i].size(); j++) {
//             if (grid[i][j] == fillChar) {
//                 std::wcout << fillChar;
//             } else {
//                 std::wcout << grid[i][j];
//             }
//         }
//         std::wcout << std::endl;
//     }
// }

// int countLivingNeighbors(std::vector<std::vector<wchar_t>> grid, int row, int col) {
//     int livingNeighbors = 0;
//     for (int i = row - 1; i <= row + 1; i++) {
//         for (int j = col - 1; j <= col + 1; j++) {
//             if (i == row && j == col) {
//                 continue;
//             }
//             if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
//                 continue;
//             }
//             if (grid[i][j] == L'\u2588') {
//                 livingNeighbors++;
//             }
//         }
//     }
//     return livingNeighbors;
// }

// // std::vector<std::vector<wchar_t>> getNextGeneration(std::vector<std::vector<wchar_t>> grid) {
// //     std::vector<std::vector<wchar_t>> newGrid;
// //     for (int i = 0; i < grid.size(); i++) {
// //         std::vector<wchar_t> newRow;
// //         for (int j = 0; j < grid[i].size(); j++) {
// //             int livingNeighbors = countLivingNeighbors(grid, i, j);
// //             if (grid[i][j] == L'\u2588') {
// //                 if (livingNeighbors < 2 || livingNeighbors > 3) {
// //                     newRow.push_back(' ');
// //                 } else {
// //                     newRow.push_back(L'\u2588');
// //                 }
// //             } else {
// //                 if (livingNeighbors == 3) {
// //                     newRow.push_back(L'\u2588');
// //                 } else {
// //                     newRow.push_back(' ');
// //                 }
// //             }
// //         }
// //         newGrid.push_back(newRow);
// //     }
// //     return newGrid;
// // }

// std::vector<std::vector<wchar_t>> getNextGeneration(const std::vector<std::vector<wchar_t>>& grid) {
//     std::vector<std::vector<wchar_t>> newGrid(grid.size(), std::vector<wchar_t>(grid[0].size(), L' '));

//     for (int i = 0; i < grid.size(); ++i) {
//         for (int j = 0; j < grid[i].size(); ++j) {
//             int livingNeighbors = countLivingNeighbors(grid, i, j);
//             if (grid[i][j] == L'\u2588') {
//                 if (livingNeighbors < 2 || livingNeighbors > 3) {
//                     newGrid[i][j] = L' ';
//                 } else {
//                     newGrid[i][j] = L'\u2588';
//                 }
//             } else {
//                 if (livingNeighbors == 3) {
//                     newGrid[i][j] = L'\u2588';
//                 }
//             }
//         }
//     }
//     return newGrid;
// }

// // create grid
// std::vector<std::vector<wchar_t>> createGrid(int rows, int cols) {
//     std::vector<std::vector<wchar_t>> grid;
//     for (int i = 0; i < rows; i++) {
//         std::vector<wchar_t> row;
//         for (int j = 0; j < cols; j++) {
//             row.push_back(' ');
//         }
//         grid.push_back(row);
//     }
//     return grid;
// }

// int main() {
//     // utf8 for the special sign
//     setlocale(LC_ALL, "en_US.UTF-8");
//     wchar_t fillChar = L'\u2588';

//     std::vector<std::vector<wchar_t>> grid = createGrid(30, 60);

//     // block
//     // grid[4][3] = fillChar;
//     // grid[4][4] = fillChar;
//     // grid[5][3] = fillChar;
//     // grid[5][4] = fillChar;

//     // blinker
//     // grid[5][8] = fillChar;
//     // grid[5][9] = fillChar;
//     // grid[5][10] = fillChar;

//     // glider
//     // grid[5][3] = fillChar;
//     // grid[6][4] = fillChar;
//     // grid[7][2] = fillChar;
//     // grid[7][3] = fillChar;
//     // grid[7][4] = fillChar;

//     // pentadecathlon
//     // grid[5][3] = fillChar;
//     // grid[6][3] = fillChar;
//     // grid[7][2] = fillChar;
//     // grid[7][4] = fillChar;
//     // grid[8][3] = fillChar;
//     // grid[9][3] = fillChar;
//     // grid[10][3] = fillChar;
//     // grid[11][2] = fillChar;
//     // grid[11][4] = fillChar;
//     // grid[12][3] = fillChar;
//     // grid[13][3] = fillChar;

//     // pulsar
//  grid[5][4] = fillChar;
// grid[5][5] = fillChar;
// grid[5][6] = fillChar;
// grid[5][10] = fillChar;
// grid[5][11] = fillChar;
// grid[5][12] = fillChar;
// grid[7][4] = fillChar;
// grid[7][9] = fillChar;
// grid[7][11] = fillChar;
// grid[7][16] = fillChar;
// grid[8][4] = fillChar;
// grid[8][9] = fillChar;
// grid[8][11] = fillChar;
// grid[8][16] = fillChar;
// grid[9][4] = fillChar;
// grid[9][9] = fillChar;
// grid[9][11] = fillChar;
// grid[9][16] = fillChar;
// grid[10][6] = fillChar;
// grid[10][10] = fillChar;
// grid[10][12] = fillChar;
// grid[10][14] = fillChar;
// grid[11][6] = fillChar;
// grid[11][10] = fillChar;
// grid[11][12] = fillChar;
// grid[11][14] = fillChar;
// grid[12][4] = fillChar;
// grid[12][9] = fillChar;
// grid[12][11] = fillChar;
// grid[12][16] = fillChar;
// grid[14][4] = fillChar;
// grid[14][5] = fillChar;
// grid[14][6] = fillChar;
// grid[14][10] = fillChar;
// grid[14][11] = fillChar;
// grid[14][12] = fillChar;

//     // int count = countLivingNeighbors(grid, 5, 3);
//     // std::wcout << "NeighbourCount: " << count << std::endl;

//     // printGrid(grid, fillChar);

//     // grid = getNextGeneration(grid);

//     // printGrid(grid, fillChar);

//     while (true) {
//         // clear console
//         // std::wcout << L"\033[2J\033[1;1H";
//         printGrid(grid, fillChar);
//         grid = getNextGeneration(grid);
//         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     }

//     return 0;
// }


// #include <wx/wx.h>
// #include "wx/wx.h"
// #include "wx/sizer.h"

// class BasicDrawPane : public wxPanel
// {
    
// public:
//     BasicDrawPane(wxFrame* parent);
    
//     void paintEvent(wxPaintEvent & evt);
//     void paintNow();
    
//     void render(wxDC& dc);
    
//     // some useful events
//     /*
//      void mouseMoved(wxMouseEvent& event);
//      void mouseDown(wxMouseEvent& event);
//      void mouseWheelMoved(wxMouseEvent& event);
//      void mouseReleased(wxMouseEvent& event);
//      void rightClick(wxMouseEvent& event);
//      void mouseLeftWindow(wxMouseEvent& event);
//      void keyPressed(wxKeyEvent& event);
//      void keyReleased(wxKeyEvent& event);
//      */
    
//     DECLARE_EVENT_TABLE()
// };


// class MyApp: public wxApp
// {
//     bool OnInit();
    
//     wxFrame *frame;
//     BasicDrawPane * drawPane;
// public:
        
// };

// IMPLEMENT_APP(MyApp)


// bool MyApp::OnInit()
// {
//     wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
//     frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello wxDC"), wxPoint(50,50), wxSize(800,600));
	
//     drawPane = new BasicDrawPane( (wxFrame*) frame );
//     sizer->Add(drawPane, 1, wxEXPAND);
	
//     frame->SetSizer(sizer);
//     frame->SetAutoLayout(true);
	
//     frame->Show();
//     return true;
// } 

// BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
// // some useful events
// /*
//  EVT_MOTION(BasicDrawPane::mouseMoved)
//  EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
//  EVT_LEFT_UP(BasicDrawPane::mouseReleased)
//  EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
//  EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
//  EVT_KEY_DOWN(BasicDrawPane::keyPressed)
//  EVT_KEY_UP(BasicDrawPane::keyReleased)
//  EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
//  */

// // catch paint events
// EVT_PAINT(BasicDrawPane::paintEvent)

// END_EVENT_TABLE()


// // some useful events
// /*
//  void BasicDrawPane::mouseMoved(wxMouseEvent& event) {}
//  void BasicDrawPane::mouseDown(wxMouseEvent& event) {}
//  void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
//  void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
//  void BasicDrawPane::rightClick(wxMouseEvent& event) {}
//  void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
//  void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
//  void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
//  */

// BasicDrawPane::BasicDrawPane(wxFrame* parent) :
// wxPanel(parent)
// {
// }

// /*
//  * Called by the system of by wxWidgets when the panel needs
//  * to be redrawn. You can also trigger this call by
//  * calling Refresh()/Update().
//  */

// void BasicDrawPane::paintEvent(wxPaintEvent & evt)
// {
//     wxPaintDC dc(this);
//     render(dc);
// }

// /*
//  * Alternatively, you can use a clientDC to paint on the panel
//  * at any time. Using this generally does not free you from
//  * catching paint events, since it is possible that e.g. the window
//  * manager throws away your drawing when the window comes to the
//  * background, and expects you will redraw it when the window comes
//  * back (by sending a paint event).
//  *
//  * In most cases, this will not be needed at all; simply handling
//  * paint events and calling Refresh() when a refresh is needed
//  * will do the job.
//  */
// void BasicDrawPane::paintNow()
// {
//     wxClientDC dc(this);
//     render(dc);
// }

// /*
//  * Here we do the actual rendering. I put it in a separate
//  * method so that it can work no matter what type of DC
//  * (e.g. wxPaintDC or wxClientDC) is used.
//  */
// void BasicDrawPane::render(wxDC&  dc)
// {
//     // draw some text
//     dc.DrawText(wxT("Testing"), 40, 60); 
    
//     // draw a circle
//     dc.SetBrush(*wxGREEN_BRUSH); // green filling
//     dc.SetPen( wxPen( wxColor(255,0,0), 5 ) ); // 5-pixels-thick red outline
//     dc.DrawCircle( wxPoint(200,100), 25 /* radius */ );
    
//     // draw a rectangle
//     dc.SetBrush(*wxBLUE_BRUSH); // blue filling
//     dc.SetPen( wxPen( wxColor(255,175,175), 10 ) ); // 10-pixels-thick pink outline
//     dc.DrawRectangle( 300, 100, 400, 200 );
    
//     // draw a line
//     dc.SetPen( wxPen( wxColor(0,0,0), 3 ) ); // black line, 3 pixels thick
//     dc.DrawLine( 300, 100, 700, 300 ); // draw line across the rectangle
    
//     // Look at the wxDC docs to learn how to draw other stuff
// }