#include "main.h"
#include "list.h"

class Menu
{
	bool SwitchAction(Queue&, Queue&, int&);
	int ChoiceQueue();
	int ChoiceAction();

	public:
		void Main();
};
