# include <Siv3D.hpp>

const int CellSize = 25;
const int BoardSize_w = 20;
const int BoardSize_h = 20;


enum class Cell {
	Empty,
	Red,
	Blue,
	Green,
	Yellow,
};


//セルを描画
void drawCell(int x, int y, Cell cell)
{
	Rect rect(x, y, CellSize, CellSize);

	Color color;
	// セルの状態に合わせて表示色をセット
	switch (cell)
	{
	case Cell::Red:
		color = Palette::Red;
		break;
	case Cell::Blue:
		color = Palette::Blue;
		break;
	case Cell::Green:
		color = Palette::Green;
		break;
	case Cell::Yellow:
		color = Palette::Yellow;
	default:
		color = Palette::Whitesmoke;
		break;
	}
	// 長方形を描く
	rect.draw(color);

	// 長方形の内側に太さ 1 の枠を描く
	rect.drawFrame(1, 0, Palette::Black);

}


//指定位置にボードを描画
void drawBoard(int x, int y, Grid<Cell> board)
{
	for (int i = 0; i < board.width; i++)
	{
		for (int j = 0; j < board.height; j++)
		{

			drawCell(x + i * CellSize, y + j * CellSize, board[j][i]);
		}
	}
	Rect rect(x, y, board.width * CellSize, board.height * CellSize);
	// 長方形の外側に太さ 2 の枠を描く
	rect.drawFrame(0, 2, Palette::Black);

}

void Main()
{
	// サイズを変えられるウィンドウにする
	Window::SetStyle(WindowStyle::Sizeable);

	// ウィンドウサイズを 幅 1200, 高さ 600 にする
	Window::Resize(1200, 600);

	// ウィンドウを中央に移動する
	Window::Centering();

	const Font font(30);
	Graphics::SetBackground(Palette::White);
	const Rect rect(100, 100, 400, 300);

	Grid<Cell> board(BoardSize_w, BoardSize_h, Cell::Empty);

	while (System::Update())
	{
		//		font(L"ようこそ、Siv3D の世界へ！").draw();

		//		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });

		//		font(Mouse::Pos()).draw(50, 200, Palette::Orange);

		//		drawCell(Mouse::Pos(), 30);

		//		drawBoard(Mouse::Pos(), board);

		//

		//ボードの表示更新
		drawBoard(50, 50, board);


	}
}
