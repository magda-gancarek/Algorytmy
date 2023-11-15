#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
class Visitor {
   public:
    virtual void Visit(T& element) = 0;
    virtual bool IsDone() const = 0; 
};

template <typename T>
class Iterator {
   public:
    virtual ~Iterator() {}
    virtual bool IsDone() const = 0;       
    virtual const T& operator*() const = 0; 
    virtual void operator++() = 0;     
};

class AddingVisitor : public Visitor<int> {
   protected:
    int sum = 0;

   public:
    AddingVisitor() : sum(0){};
    int Sum() { return sum; }
    void Visit(int& i) {
        sum += i;
    }
    void clean() {
        sum = 0;
    }
    bool IsDone() const { return false; }
};

class WizytatorDrukujacyInty : public Visitor<int> {
   public:
    virtual void Visit(int& value) {
        std::cout << value << '\n';
    }
    bool IsDone() const { return false; }
};

class OddVisitor : public Visitor<int> {
  protected:
    bool odd = false;

   public:
    void Visit(int& i) {
        if (i % 2) {
            odd = true;
           // std::cout << i << " is odd number\n";
        }
    }
    bool IsDone() const {
        return odd;
    }
		bool CzyJestNieparzysta(){
			return odd;
		}
};

template <typename T>
class Container {
   protected:
    Container(){};

   public:
    virtual int Count() const = 0;
    virtual bool IsEmpty() const { return Count() == 0; };
    virtual bool IsFull() const = 0;
    virtual void MakeNull() = 0;
    virtual void Accept(Visitor<T>& v) = 0;
};

template <typename T>
class Set : public Container<int> {
   protected:
    int count = 0;
    int universeSize;

   public:
    Set(int n) : universeSize(n) {}
    int UniverseSize() const { return universeSize; }
    int Count() const { return count; };
    virtual void Insert(T element) = 0;
    virtual bool IsMember(T element) const = 0;
    virtual void Withdraw(T element) = 0;
};

class SetAsArray : public Set<int> {
   public:
    class Iter : public Iterator<int> {
        std::vector<bool> data;
        int universeSize;
        int index;
        int last_index;

       public:
        Iter(std::vector<bool> array, int us) {
            data = array;
            universeSize = us;
            for (unsigned int i = 0; i < us; ++i) {
                if (data[i]) {
                    index = i;
                    break;
                }
            }
        };
        ~Iter(){};
        const int& operator*() const {  

            return index;
        };
        void operator++() {  
            for (unsigned int i = index + 1; i <= universeSize; ++i) {
                if (i == universeSize || data[i]) {
                    index = i;
                    break;
                }
            }
        };
        bool IsDone() const { 
            if (index == universeSize) {
                return true;
            }
            return false;
        };
    };

    std::vector<bool> array;

    SetAsArray(unsigned int n) : Set(n) {
        array = std::vector<bool>(n, false);
    }
    void MakeNull(){}; 
    bool IsFull() const { 
			return (Count() == UniverseSize()); 
		};
    void Insert(int element) {
        if (!array[element]) {
            array[element] = true;
            count++;
        }
    }
    bool IsMember(int element) const {
        if (element >= this->universeSize || element < 0) return false;
        return this->array[element];
    }
    void Withdraw(int element) {
      if (array[element]) {
            array[element] = false;
            count--;
        }
    }

	void Accept(Visitor<int>& v) {
		int elem = 0;
		int count2 = 0;
		while(count2 < count && v.IsDone() == false){
			if (array[elem] == true) {
		    v.Visit(elem);
				count2++;
			}
		elem++;
		}
		std::cout <<"Accept: Zatrzymałem przeglądanie na elemencie: " << count2 << std::endl;
	}

    
    friend SetAsArray operator+(
        SetAsArray const& first, SetAsArray const& second) {
        int size = 0;
        if (first.universeSize == second.universeSize) {
            size = first.universeSize;
        } else {
        }
        SetAsArray result(size);
        for (unsigned int i = 0; i < size; ++i) {
            result.array[i] = first.array[i] || second.array[i];
        }
        result.count = first.Count() + second.Count();
        return result;
    }

    friend SetAsArray operator-(
        SetAsArray const& first, SetAsArray const& second) {
        int size = 0;
        if (first.universeSize == second.universeSize) {
            size = first.universeSize;
        } else {
        }
        SetAsArray result(size);
        for (unsigned int i = 0; i < size; ++i) {
            result.array[i] = first.array[i] && !second.array[i];
            if (result.array[i]) {
                result.count++;
            }
        }
        // result.count = first.Count() - second.Count();
        return result;
    }
    friend SetAsArray operator*(
        SetAsArray const& first, SetAsArray const& second) {
        int size = 0;
        if (first.universeSize == second.universeSize) {
            size = first.universeSize;
        } else {
        }
        SetAsArray result(size);
        for (unsigned int i = 0; i < size; ++i) {
            result.array[i] = first.array[i] && second.array[i];
            if (result.array[i]) {
                result.count++;
            }
        }

        return result;
    }
    friend bool operator==(
        SetAsArray const& first, SetAsArray const& second) {
        int size = 0;
        if (first.universeSize == second.universeSize) {
            size = first.universeSize;
        } else {
        }
        for (unsigned int i = 0; i < size; ++i) {
            if (first.array[i] != second.array[i]) {
                return false;
            }
        }
        return true;
    }
    friend bool operator<=(
        SetAsArray const& first, SetAsArray const& second) {
        int size = 0;
        if (first.universeSize == second.universeSize) {
            size = first.universeSize;
        } else {
        }
        for (unsigned int i = 0; i < size; ++i) {
            if (first.array[i] == second.array[i]) {
                return true;
            }
        }
        return false;
    }
    void Wypisz() {
        for (int i = 0; i < universeSize; ++i) {
            if (array.at(i)) {
                std::cout << i << ' ';
            }
        }
        std::cout << '\n';
    }

    Iter NewIterator() {
        return Iter(array, universeSize);
    };
};


int main() {
	  SetAsArray A(10);
    SetAsArray B(10);
    SetAsArray C(10);
    SetAsArray D(10);

    for(int i = 0; i < 10; i++){
			if(i%2 == 0){
				A.Insert(i);
			}
			if(i%2 != 0){
				B.Insert(i);
			}
	}
    C = A + B;
    D = C - B;

    std::cout << "A: ";
    A.Wypisz();
		std::cout << A.Count() << std::endl;
    std::cout << "B: ";
    B.Wypisz();
		std::cout << B.Count() << std::endl;
		std::cout << "C: ";
    C.Wypisz();
		std::cout << C.Count() << std::endl;
    std::cout << "D: ";
    D.Wypisz();
		std::cout << D.Count() << std::endl;

		if(D==A){
	std::cout << "Zbiory A i D są takie same" << std::endl;
}else{
	std::cout << "Zbiory A i D są różne" << std::endl;
}
	
if(D<=A){
	std::cout << "Zbiory D zawiera się w A" << std::endl;
}else{
	std::cout << "Zbiory D NIE zawiera się w A" << std::endl;
}

if(C==B){
	std::cout << "Zbiory C i B są  takie same" << std::endl;
}else{
	std::cout << "Zbiory C i B są różne" << std::endl;
}


if(B<=C){
	std::cout << "Zbiory B zawiera się w C" << std::endl;
}else{
	std::cout << "Zbiory B NIE zawiera się w C" << std::endl;
}

    A.Insert(1);
    std::cout << "A : ";
    A.Wypisz();

    if(D==A){
	std::cout << "Zbiory A i D są  takie same" << std::endl;
			}else{
	std::cout << "Zbiory A i D są różne" << std::endl;
}


if(D<=A){
	std::cout << "Zbiory D zawiera się w A" << std::endl;
}else{
	std::cout << "Zbiory D NIE zawiera się w A" << std::endl;
}

		std:: cout << std::endl;
	
		A.Insert(5);
    std::cout << "A: ";
    A.Wypisz();

	
    AddingVisitor v_A; 
    A.Accept(v_A);
    std::cout << "Sum = " << v_A.Sum() << '\n';

    SetAsArray E(10);
    E = A * B;
    std::cout << "E: ";
    E.Wypisz();

    AddingVisitor v_E;
    E.Accept(v_E);
    std::cout << "Sum = " << v_E.Sum() << '\n';
    v_E.clean();

    E.Withdraw(1);
    std::cout << "E: ";
    E.Wypisz();
   E.Accept(v_E);
    std::cout << "Sum = " << v_E.Sum() << '\n';

	std::cout<< std::endl;
	 	std::cout<< "Nowe testy" << std::endl;

		B.Wypisz();
		OddVisitor v2_B;
    B.Accept(v2_B);
    std::cout << "Czy w zbiorze B jest liczba nieparzysta = " << v2_B.CzyJestNieparzysta() << '\n';

		A.Wypisz();
		OddVisitor v2_A;
    A.Accept(v2_A);
    std::cout << "Czy w zbiorze A jest liczba nieparzysta = " << v2_A.CzyJestNieparzysta() << '\n';


	A.Withdraw(1);
	A.Withdraw(5);
	A.Wypisz();

	OddVisitor v3_A;
    A.Accept(v3_A);
    std::cout << "Czy w zbiorze A jest liczba nieparzysta = " << v3_A.CzyJestNieparzysta() << std::endl;

  std::cout << "\nIterator\n"; 
	std::cout << "A: ";
	auto A_iter = A.NewIterator();
	 while (!A_iter.IsDone()) {
        std::cout << *A_iter << ' ';
        ++A_iter;
    }
    std::cout << '\n';
	
	auto B_iter = B.NewIterator();
    std::cout << "B: ";
    while (!B_iter.IsDone()) {
        std::cout << *B_iter << ' ';
        ++B_iter;
    }
    std::cout << '\n';
}