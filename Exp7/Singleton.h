#pragma once

#include <memory>
#include <mutex>

class Singleton
{
public:
	static std::shared_ptr<Singleton> get_instance();
	int res;
	static std::once_flag instance_created;
	static std::shared_ptr<Singleton> instance;
private:
	Singleton(int r) :res(r) {}
	Singleton(Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

