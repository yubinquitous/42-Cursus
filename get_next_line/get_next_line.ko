# **Get Next Line**

##### Reading a line on a fd is way too tedious

fd에서 한 줄을 읽는다는 것은 너무나도 지루한 일입니다.

##### _Summary: The aim of this project is to make you code a function that returns a line, read from a file descriptor._

_요약: 이 프로젝트의 목적은 파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수를 코드화 하는 것입니다._

<br>

# Contents

| Chapter | Contents                                         | page |
| :-----: | :----------------------------------------------- | :--: |
|    1    | [**Goals**](#Chapter-1)                          |  2   |
|    2    | [**Common Instrunctions**](#Chapter-2)           |  3   |
|    3    | [**Mandatory part - Get_next_line**](#Chapter-3) |  4   |
|    4    | [**Bonus part**](#Chapter-4)                     |  6   |

<br>

# **Chapter 1**

## Goals

<br>

##### _This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables._

이 프로젝트는 당신의 콜렉션(아마 라이브러리)에 아주 편리한 함수를 추가하게 할 뿐만 아니라, C 프로그래밍에 있어서 아주 흥미롭고 새로운 개념인 '정적 변수'를 배울 수 있도록 도울 것입니다.

<br>

# **Chapter 2**

## Common Instructions

<br>

- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside._

  프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 존재할 경우, 그 또한 norm 검사에 포함되며 norm error가 있을 시 0점을 받게 됩니다.

- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._

  함수들은 정의되지 않은 행동들과 별개로 예기치 않게 중단되어서는 안 됩니다.(예를 들어, segmentation fault, bus error, double free 등) 만약 이렇게 중단되면, 당신의 프로젝트는 작동하지 않는 것으로 여겨지고 평가에서 0점을 받을 것입니다.

- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._

  필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용납될 수 없습니다.

- ##### _If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink._

  과제에서 필요한 경우, **-Wall -Wextra -Werror** 플래그를 지정하여 컴파일을 수행하는 **Makefile**을 제출해야 합니다. Makefile은 relink 되어서는 안 됩니다.

- ##### _Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re._

  **Makefile**은 최소한 **$(NAME), all, clean, fclean, re** 규칙을 포함해야 합니다.

- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h}. Mandatory and bonus part evaluation is done separately._

  프로젝트에 보너스를 제출하려면, Makefile에 **보너스 규칙**을 포함해야 합니다. 이 보너스 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리, 또는 함수들을 추가하여야 합니다. 보너스 과제는 반드시 \_**bonus**.{c/h}라는 별도의 파일에 있어야 합니다. 반드시 수행하여야 하는 메인 파트의 평가와 보너스 파트의 평가는 별도로 이뤄집니다.

- ##### _If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project._

  만일 프로젝트에서 여러분의 libft 사용을 허용한다면, 소스들과 관련 Makefile을 함께 루트 폴더 안에 있는 libft 폴더에 복사해야 합니다. 프로젝트의 Makefile은 우선 libft의 Makefile을 사용하여 라이브러리를 컴파일한 다음, 프로젝트를 컴파일해야 합니다.

- ##### _We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._

  **이 과제물을 제출할 필요가 없고, 채점 받을 필요가 없을지라도,** 저희는 여러분들이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이것은 여러분의 과제물과 동료들의 과제물을 쉽게 테스트할 수 있게 도울 것입니다. 또한, 평가를 진행할 때 이러한 테스트 프로그램들이 특히 유용하다는 사실을 알게 될 것입니다. 평가 시에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 당연히 자유롭게 사용할 수 있습니다.

- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._
  할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 등급이 매겨질 것입니다. Deepthought가 평가하는 과제의 경우엔, 동료평가 이후에 Deepthought가 수행됩니다. 만약 Deepthought 평가 중에 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.

<br>

# Chapter 3

## Mandatory part - Get_next_line

<br>

| **함수 이름**                | get_next_line                                                                     |
| ---------------------------- | --------------------------------------------------------------------------------- |
| **프로토타입**               | char \*get_next_line(int fd);                                                     |
| **제출할 파일**              | get_next_line.c, get_next_line_utils.c, get_next_line.h                           |
| **매개변수**                 | 읽어들일 파일의 디스크립터 (서술자)                                               |
| **반환값**                   | 읽혀진 라인 : 한 줄이 제대로 읽힘 <br> NULL : 읽을 라인이 더이상 없거나 에러 발생 |
| **사용가능한 <br>외부 함수** | `read, malloc, free`                                                              |
| **설명**                     | 파일 디스크립터로부터 한 줄을 읽고, <br>반환하는 함수를 작성하시오.               |

<br>

- ##### _Calling your function `get_next_line` in a loop will then allow you to read the text available on the file descriptor one line at a time until the end of it._

  `get_next_line` 함수를 반복문 안에서 호출하면, 파일 디스크립터에 존재하는 텍스트를 EOF 전까지 한 번에 한 줄씩 읽어들일 수 있습니다.

- ##### _Your function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL._

  여러분의 함수는 방금 읽어들인 문자열 한 줄을 반환하여야 합니다. 더이상 읽어올 것이 없거나 에러가 발생하면 NULL을 반환하여야 합니다.

- ##### _Make sure that your function behaves well when it reads from a file and when it reads from the standard input._

  파일에서 읽을 때, 표준입력으로부터 읽어들일 때 모두 함수가 제대로 동작하는지 확인하십시오.

- ##### _`libft` is not allowed for this project. You must add a `get_next_line_utils.c` file which will contain the functions that are needed for your `get_next_line` to work._

  `libft`는 이 프로젝트에서 사용할 수 없습니다. 대신 `get_next_line_utils.c` 파일에 과제를 수행하는 데 필요한 함수들을 정의해야 합니다.

- ##### _Your program must compile with the flag `-D BUFFER_SIZE=xx` which will be used as the buffer size for the read calls in your `get_next_line`. This value will be modified by your evaluators and by the moulinette._

  당신의 프로그램은 `-D BUFFER_SIZE=xx` 플래그를 이용하여 컴파일 되어야 합니다. 이것은 여러분의 `get_next_line`에서 read함수를 호출하기 위한 buffer size로 사용될 것이며, Moulinette와 평가자가 임의로 값을 수정하여 테스트할 것입니다.

- ##### _The program will be compiled in this way: `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`._

  컴파일은 이런 식으로 진행됩니다 : <br>`gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <파일들>.c`

- ##### _Your read must use the `BUFFER_SIZE` defined during compilation to read from a file or from stdin. This value will be modified during the evaluation for testing purposes._

  `read` 함수를 사용할 때에는, 파일 또는 표준 입력으로부터 값을 읽어들이기 위해 컴파일 시에 정의되는 `BUFFER_SIZE`를 사용해야 합니다. 평가 시에, 함수 테스트를 위하여 값이 변동될 수 있습니다.

- ##### _In the header file `get_next_line.h` you must have at least the prototype of the function `get_next_line`._

  `get_next_line.h` (헤더 파일)에는 적어도 `get_next_line` 함수의 프로토타입이 존재하여야 합니다.

> 💡<br>
>
> ##### _Does your function still work if the BUFFER_SIZE value is 9999? And if the BUFFER_SIZE value is 1? And 10000000? Do you know why?_
>
> BUFFER_SIZE 값이 9999인 경우에도 함수는 여전히 작동하나요? BUFFER_SIZE 값이 1이라면? 10000000이라면? 왜 그런지 아시나요?

> 💡 <br>
>
> ##### _You should try to read as little as possible each time get_next_line is called. If you encounter a newline, you have to return the current line. Don’t read the whole file and then process each line._
>
> get_next_line이 호출될 때마다 가능한 한 적게 읽어들이도록 해야 합니다. 만약 newline을 만나면, 현재 라인을 반환해야 합니다. 전체 파일을 읽어들인 다음에 한줄씩 처리하려 하지 마세요.

> 💡<br>
>
> ##### _Don’t turn in your project without testing. There are many tests to run, cover your bases. Try to read from a file, from a redirection, from standard input. How does your program behave when you send a newline to the standard output? And CTRL-D?_
>
> 테스트하지 않고 프로젝트를 제출하지 마세요. 여러분의 함수를 위해 돌려볼 수 있는 테스트는 많습니다. 파일로부터, redirection으로부터, stdin으로부터의 읽기를 시도해 보세요. 표준 출력에 newline을 보낼 때 프로그램은 어떻게 동작하나요? CTRL-D는요?

- ##### _lseek is not an allowed function. File reading must be done only once._

  `lseek`은 허용된 함수가 아닙니다. 파일 읽기는 오로지 한번만 행해져야 합니다.

- ##### _We consider that `get_next_line` has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd._

  만약 동일한 파일 디스크립터의 두 호출 사이에서, 첫 번째 fd에서 EOF에 도달하기 전에 다른 파일로 전환될 경우, 우리는 `get_next_line`이 정의되지 않은 동작을 가진다고 생각합니다.

- ##### _Finally we consider that `get_next_line` has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent._

  마지막으로 `get_next_line`은 바이너리 파일을 읽을 때 정의되지 않은 동작을 가진다고 생각하셔야 합니다. 그러나 여러분이 원한다면 이러한 동작을 논리적으로 구현하셔도 됩니다.

- ##### _Global variables are forbidden._

  전역 변수는 금지되어 있습니다.

- ##### _Important: You should always return the line that has been read followed by a ’`\n`’ unless you have reach end of file and the is no ’`\n`’._
  중요: 함수는 'eof에 도달하였고 `\n`이 존재하지 않을 때'를 제외하곤, 항상 `\n`이 뒤따라오는 한 줄을 읽고 해당 한 줄을 반환하여야 합니다.

> ℹ️ <br>
>
> ##### _A good start would be to know what a static variable is:_
>
> 정적 변수가 무엇인지 익혀 두면 좋은 시작이 될 겁니다 : <br> https://en.wikipedia.org/wiki/Static_variable

<br>

# Chapter 4

## Bonus part

<br>

##### _The project `get_next_line` is straightforward and leaves very little room for bonuses, but we are sure that you have a lot of imagination. If you have aced the mandatory part, then by all means, complete this bonus part to go further. Just to be clear, no bonuses will be taken into consideration if the mandatory part isn’t perfect._

`get_next_line` 프로젝트는 간단하기 때문에 보너스를 받을 만한 여지가 거의 없지만, 우리는 여러분의 상상력이 풍부하다고 확신합니다. 만약 여러분이 필수적으로 해야하는 부분들을 완벽하게 숙달했다면, 어떻게든 보너스 파트를 완성하고 더 앞으로 나아가세요. 다시 말하지만, 필수적으로 해야하는 부분들이 완벽하지 않다면, 보너스는 고려되지 않을 것입니다.

##### _Turn-in all 3 mandatory files ending by \_bonus.[c\h] for this part._

이 파트를 위해서는 기존의 3개 파일에 \_bonus를 붙여서 제출하세요.

- ##### _To succeed `get_next_line` with a single static variable._

  하나의 정적변수로 `get_next_line` 성공하기.

- ##### _To be able to manage multiple file descriptors with your `get_next_line`. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call `get_next_line` once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors._
  `get_next_line`을 사용하여 여러 개의 파일 디스크립터를 관리할 수 있는 것. 예를 들어, 파일 디스크립터 3, 4, 5에 접근 가능한 경우, `get_next_line`은 각 디스크립터의 리딩 스레드를 잃지 않은 채로 3에서 한 번, 4에서 한 번, 다시 3에서 한 번, 5에서 한 번 호출될 수 있습니다.
