#include <iostream>

// Circular Queue

const int QUEUE_SIZE = 10;

enum Comman
{
	ENQUEUE = 1,
	DEQUEUE = 2
};

// ���� ���� head, ���� �� tail ���� �ʿ�

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
		i = (i + 1) % QUEUE_SIZE;	// �ܼ��� i++�� �Ѵٸ�
									// i�� ũ�⸦ �Ѿ�� ������� ��� �Ұ���
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

	queue.tail = (queue.tail + 1) % QUEUE_SIZE;	// QUEUE_SIZE�� ������
	queue.container[queue.tail] = value;
}

void Dequeue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		return;
	}

	queue.head = (queue.head + 1) % QUEUE_SIZE;	// QUEUE_SIZE�� ������
	std::cout << queue.container[queue.head] << " dequeue!" << std::endl;
}

// index�� ������ �־
// �ݵ�� QUEUE_SIZE�� �����߸� ���� ť�� ���������.

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
				std::cout << "�߸��� ��ɾ��Դϴ�." << std::endl;
				break;
		}
	}
}

// SIZE 10�� �߿��� 9���ۿ� ������..
// 10�� �� �� �� �ִ� �����?