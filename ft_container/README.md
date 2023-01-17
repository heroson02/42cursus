ft_container
------------
기간 : 2022.11.10 ~ 2022. 12.13

본 프로젝트의 목표는 다양한 C++ STL(Standard Template Library) Container 타입들을 구현하는 것이다. 각각의 컨테이너들을 reference를 참고해 <container>.hpp 형식의 파일안에 적절한 클래스들을 작성해 구현하면 된다. container, iterator을 제외하고 모두 C++98 버전에서 진행되어야 한다.

- **`vector`**
    - `vector<bool>` 은 하지 않아도 된다.
- **`map`**
- **`stack`**
    - 직접 만든 `vector` 클래스를 기본 기저 컨테이너로 사용하되, STL의 `stack`이 포함하는 다른 컨테이너들과도 호환되어야 한다.
- **`set`** **(Bonus Part)**
    - **Red-Black tree**를 사용하여 구현해야 한다.

보너스까지 완료하였고, set과 map은 같은 red-black tree를 기반으로 구현하였다.
