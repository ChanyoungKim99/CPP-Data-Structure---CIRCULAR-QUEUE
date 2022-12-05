#include <iostream>

// Circular Queue

const int QUEUE_SIZE = 10;

enum Comman
{
	ENQUEUE = 1,
	DEQUEUE = 2
};

// 줄의 시작 head, 줄의 끝 tail 지정 필요

struct Queue
{
	int container[QUEUE_SIZE];
	int head = 0;
	int tail = 0;
};

void PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl;
	std::cout << "[1] enqueue" << std::endl;
	std::cout << "[2] dequeue" << std::endl;
	std::cout << "-----------" << std::endl;
}

void PrintQueue(Queue& queue)
{
	std::cout << "--- queue ---" << std::endl;

	if (queue.head == queue.tail)
	{
		std::cout << "EMPTY" << std::endl;
		return;
	}

	int i = queue.head;
	while (i != queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE;	// 단순히 i++를 한다면
									// i가 크기를 넘어갈때 순서대로 출력 불가능
		std::cout << queue.container[i] << " ";
	}
	std::cout << std::endl << "-------------------" << std::endl;
}

void Enqueue(Queue& queue, int value)
{
	if (queue.head == (queue.tail + 1) % QUEUE_SIZE)
	{
		std::cout << "Queue is FULL!!" << std::endl;
		return;
	}

	queue.tail = (queue.tail + 1) % QUEUE_SIZE;	// QUEUE_SIZE로 나누기
	queue.container[queue.tail] = value;
}

void Dequeue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		return;
	}

	queue.head = (queue.head + 1) % QUEUE_SIZE;	// QUEUE_SIZE로 나누기
	std::cout << queue.container[queue.head] << " dequeue!" << std::endl;
}

// index의 증감에 있어서
// 반드시 QUEUE_SIZE로 나눠야만 원형 큐가 만들어진다.

int main()
{
	int command{};
	Queue myQueue;

	PrintInfo();

	while (true)
	{
		PrintQueue(myQueue);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case ENQUEUE:
			{
				int value;
				std::cout << "\tvalue >> ";
				std::cin >> value;
				Enqueue(myQueue, value);
				break;
			}
				
			case DEQUEUE:
				Dequeue(myQueue);
				break;

			default:
				std::cout << "잘못된 명령어입니다." << std::endl;
				break;
		}
	}
}

// SIZE 10개 중에서 9개밖에 못쓴다..
// 10개 다 쓸 수 있는 방법은?