#include <cstring>
#include <iostream>

using namespace std;

template <typename K,typename V>
class Map 
{ private:
    int ct = 0;
    struct elementMap
    {
        K key;
        V value;
        int index;

    };
    elementMap* elemente;
public:
    Map()
    {
        this->elemente = nullptr;
        this->ct = 0;
    }

    ~Map()
    {
        delete[] elemente;
    }

    int Count()
    {
        return ct;

    }

    void Clear()
    {
        delete[] elemente;
        elemente = nullptr;
        ct = 0;

    }

    void Set(const K& key, const V& value)
    {  ///daca exista deja elementul
        int i;
        for (i = 0;i < ct;i++)
            if (elemente[i].key == key) { elemente[i].value = value;return; }
     ///in caz contrar,daca nu exista
        elementMap* aux = new elementMap[ct + 1];
        for (i = 0;i < ct;i++)
            aux[i] = elemente[i];
        aux[ct].key = key;
        aux[ct].value = value;
        aux[ct].index = ct;
        ct++;
        delete[] elemente;
        elemente = aux;

    }

    bool Get(const K& key, V& value)
    {
        //daca exista
        int i;
        for (i = 0;i < ct;i++)
        
            if (elemente[i].key == key) 
             { 
                value = elemente[i].value;
                return true; 
             }

        //daca nu exista
        return false;

    }

    bool Delete(const K& key)
    {
        //daca exista
        int i,j;
        for (i = 0;i < ct;i++)
        { if(elemente[i].key==key)
          { 
            elementMap* aux = new elementMap[ct - 1];
            for (j = 0;j < i;j++)
                aux[j] = elemente[j];
            for (j = i;j < ct - 1;j++)
            {
                elemente[j + 1].index--;
                aux[j] = elemente[j + 1];

            }
            ct--;
            delete[] elemente;
            elemente = aux;
            return true;

          }

        }
      //daca nu exista
        return false;

    }


    bool Includes(const Map<K, V>& map)
    {
        if (map.ct > ct)
            return false;
        //verificam toate cheile mapei incluse
        int i, j;
        bool ok = 0;
        for (i = 0;i < map.ct;i++)
        {
            ok = 0;
            for (j = 0;j < ct;j++)
             if (map.elemente[i].key == elemente[j].key) { ok = 1;break; }
           if (ok == 1) return false;
            

        }
        return true;

    }

    V& operator[](const K& key)
    {
        //daca exista
        int i;
        for (i = 0;i < ct;i++)
            if (elemente[i].key == key) return elemente[i].value;
        //daca nu exista
        Set(key, "");//cream
        return elemente[ct - 1].value;

    }
    const elementMap* begin() const
    {
        return &elemente[0];
    }

    const elementMap* end() const
    {
        return &elemente[ct];
    }

};





int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";


    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
