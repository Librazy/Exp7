#include "Singleton.h"


std::once_flag Singleton::instance_created;
std::shared_ptr<Singleton> Singleton::get_instance()
{
	static std::shared_ptr<Singleton> instance;
	std::call_once(
		instance_created,
		[]() {instance = std::shared_ptr<Singleton>(new Singleton(0)); });
	return instance;
}
