#include "cmath"
#include "kf/kf_log.h"
#include "example.h"
#include "Scene.h"
#include "LevelOne.h"

using namespace std;
void SaveLoad();

int main()
{
	Example::inst().run();

	Scene* s = new LevelOne();
	s->update();

    return 0;
}
void SaveLoad()
{

}

