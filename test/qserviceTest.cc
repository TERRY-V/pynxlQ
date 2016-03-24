#include "../core/qservice.h"

using namespace niu;

class QTestService : public QService {
	public:
		QTestService() {}
		virtual ~QTestService() {}

	public:
		virtual int32_t init()
		{
			return 0;
		}

		virtual int32_t run(int32_t argc, char** argv)
		{
			while(1);
			return 0;
		}

		virtual int32_t destroy()
		{
			return 0;
		}
};

int main(int argc, char** argv)
{
	QTestService app;
	return app.main(argc, argv);
}
