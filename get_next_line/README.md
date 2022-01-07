# get_next_line
## Summary
The aim of this project is to make you code a function that returns a line,
read from a file descriptor.
</br>
## Goals
This project will not only allow you to add a very convenient function to your collection,
but it will also allow you to learn a highly interesting new concept in C programming:
static variables.
</br></br>
### :round_pushpin: 자세한 정리는 [노션](https://yubinquitous.notion.site/get_next_line-3d4bcd288641410e9189f3b3fdc1dab9)에서 볼 수 있다.

## mandatory

- **get_next_line.h**

  - `BUFFER_SIZE` : gcc -D 옵션으로 외부에서 define되기 때문에 `#ifndef` 을 통해 적당한 값을 정의해두었다.
  - libft 과제에서 구현한 `ft_*` 를 가져와서 사용했다.

  ---

- **get_next_line.c**

  - `char	*read_file(int fd, char *save)`

    - `BUFFER_SIZE` 만큼씩 읽어오면서 `save` 에 `ft_strjoin` 을 이용해 이어 붙인다.
    - 개행을 만나거나 파일의 끝(EOF)일 경우 반복문 종료.
    - free
      - `save`에 `buf`를 이어붙인 후 `tmp(이전 save)`를 free
      - read 반복이 끝난 후 read를 받던 `buf` 를 free

  - `char	*get_line(char *save)`

    - `save` 에서 한 줄만큼 복사해오는 함수.
    - **❗**복사한 결과값의 마지막에 `\0`  붙여준다.

  - free

    - `tmp` , 즉 `save = ft_strdup(save + ft_strlen(line));` 를 하면서 남게 된 `ft_strlen(line)` 만큼의 `이전 save`를 free.
    - EOF를 만났을 경우 `save` 를 free.

  - `char	*get_next_line(int fd)`

    - `if (!save)` 문과 `if (*save)` 문 다음 코드의 의미

      : 해당 파일을 다 읽었을 경우 수행할 코드

    - 널가드를 한 이유

      ```c
      	if (*save)
      	{
      		// ...
      		save = ft_strdup(save + ft_strlen(line));
      		if (!save)
      			return (NULL);
      		// ...
      	}
      ```

      - 위의 코드는 현재 호출된 함수가 아닌 다음 함수를 위한 코드이다. `ft_strdup` 에서 할당에 실패했을 경우 당장의 `return (line);` 에 문제가 되지 않는다.

        하지만 다음 함수 호출 시 `save == NULL`이라면 어느 부분에서 문제가 발생한지 모르기 때문에 현재 함수에서 NULL을 리턴하도록 했다.

        

---



## bonus

- **get_next_line_bonus.c**

  - `t_lst	*find_fd(t_lst	*head, int fd)`

    - 매개변수로 받은 fd가 있는 lst를 찾는 함수

    - 없다면 맨 앞, 즉 `head` 바로 뒤에 생성

      <img width="70%" src="https://user-images.githubusercontent.com/65652094/147246085-2ffc8282-433a-4f9f-a84e-1fd06944b548.gif"> </br>
      ```c
      lst->fd = fd;
      	lst->prev = head;
      	lst->next = head->next;
      	if (head->next)
      		head->next->prev = lst;
      	head->next = lst;
      	lst->save = NULL;
      ```

      - head를 만든 이유

        : node를 삭제하고 이어붙일 때 편리하다.

      - new node를 연결리스트 맨 뒤가 아닌 head 뒤에 붙인 이유

        : 연결리스트 맨 뒤에 붙인다면 `lst->prev = head;` 와 같이 간단한 코드로 해결되지 않고 맨 뒤 lst를 담을 tmp 구조체 변수가 하나 더 필요해진다.

        코드의 간결성을 위해 위와 같이 구현했다.

  - `char	*read_file(int fd, char *save)`

    - mandatory의 `read_file` 함수와 같다.

  - `char	*get_line(char *save)`

    - mandatory의 `get_line` 함수와 같다.

  - `char	*return_line(t_lst	**tmp)`

    - 결과적으로 리턴할 line을 만드는 함수
    - 할당 실패 또는 EOF일 경우 ⇒ NULL 리턴
    - free
      - `save_tmp`, 즉 `lst->save = ft_strdup(lst->save + ft_strlen(line));` 를 하면서 남게 된 `ft_strlen(line)` 만큼의 `이전 lst→save` 를 free.

  - `char	*get_next_line(int fd)`

    - `line = return_line(&lst);` 에서 line == NULL인 경우

      : 할당 실패 또는 EOF ⇒ `lst`를 지우고 `lst→prev`와 `lst→next`를 이어야 함

      <img width="70%" src="https://user-images.githubusercontent.com/65652094/147246492-e2bd6f4c-b085-4e77-a0f1-348cb8eec7d3.gif"> </br>   
      ```c
      lst->prev->next = lst->next;
      		if (lst->next)
      			lst->next->prev = lst->prev;
      		free(lst);
      		lst = NULL;
      ```
