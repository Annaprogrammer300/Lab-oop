#pragma once

namespace function {

	enum class Type {
		log,
		power,
		log_pp

	};

	class Function {
	private:
		Type _type;
		float _a;
		float _b;
		float _c;//����� ������ ��� ���������

	public:
		Function();
		Function(Type type, float a, float b);
		Function(Type type, float c);
		Type get_type() const;//�������� ���
		float get_a() const;//�������� �
		float get_b() const;
		float get_c() const;
		float compute_value(float x) const;//��������� ��������
		Function compute_derivative() const;//��������� �����������
		Function compute_antiderivative() const;


	};

	//std::ostream& operator<<(std::ostream& stream, const Function& f);

	class FunctionList {
	public:
		//static const int N = 10;
		FunctionList();
		FunctionList(const FunctionList& copy);
		void swap(FunctionList& rhs) noexcept;
		FunctionList& operator=(FunctionList copy);
		~FunctionList();
		int get_size() const;
		const Function& operator[](int index) const;
		Function& operator[](int index);
		void insert(int index, Function f);
		void add(const Function& _F);
		int last_min(const double x);
		void remove(int index);
		void clear();
	private:
		Function** listf;
		int _size;
	};

	//std::ostream& operator<<(std::ostream& stream, const FunctionList& f);
}
