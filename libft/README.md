# LIBFT
## Summary
This project aims to code a C library regrouping usual functions that you’ll
be use for all your next projects.
</br>
## Introduction
C programming can be very tedious when one doesn’t have access to those highly useful
standard functions. This project allows you to re-write those functions, understand them,
and learn to use them. This library will help you with all your future C projects.
</br></br>
### :round_pushpin: 자세한 정리는 [notion](https://yubinquitous.notion.site/Libft-dab16b6d34e548b997e065ef843744ab)에서 볼 수 있다.
- Part1: Libc functions
    - ft_atoi
        - man page
            
            **SYNOPSIS**
            #include <stdlib.h>
            
            ```c
             int
             **atoi**(const char *str);
            ```
            
            **DESCRIPTION**
            The **atoi**() function converts the initial portion of the string pointed to by str to int representation.
            
             It is equivalent to:
                   (int)strtol(str, (char **)NULL, 10);
             While the **atoi**() function uses the current locale, the atoi_l() function may be passed a locale directly. See xlocale(3) for more information.
            
        - 함수 설명
            - 문자열을 숫자로 바꿔주는 함수
            - 우선 공백(whitespace)를 모두 지나치고 '-' 또는 '+'로 부호를 판별한 후 숫자('0' ~ '9')가 아닌 값이 나올 때까지 숫자로 바꿔준다.
            - 리턴값: 변환된 숫자
                - long형을 넘어서는 값
                    - 오버플로우(long max 초과) ⇒ long max, 즉 -1 리턴
                    - 언더플로우(long min 이하) ⇒  long min, 즉 0 리턴
            - code
                
                ```c
                static int	is_space(char c)
                {
                	if (c == '\t' || c == '\f' || c == '\n'
                		|| c == '\r' || c == '\v' || c == ' ')
                		return (1);
                	return (0);
                }
                
                int	ft_atoi(const char *str)
                {
                	int		i;
                	long	sign;
                	long	result;
                
                	i = 0;
                	while (is_space(str[i]))
                		i++;
                	sign = 1;
                	if (str[i] == '-' || str[i] == '+')
                	{
                		if (str[i] == '-')
                			sign *= -1;
                		i++;
                	}
                	result = 0;
                	while (ft_isdigit(str[i]))
                		result = (result * 10) + (str[i++] - '0');
                	if (result < 0)
                		return ((sign + 1) / -2);
                	return (result * sign);
                }
                ```
                
                - `long long`을 쓰지 않고 `long`을 쓴 이유
                    
                    : `long long`을 쓰면 32-bit에서 문제가 발생한다.
                    
    - ft_bzero
        - man page
            
            **SYNOPSIS**
            #include <strings.h>
            
            ```c
             void
             **bzero**(void *s, size_t n);
            ```
            
            **DESCRIPTION**
            The **bzero**() function writes n zeroed bytes to the string s.  If n is zero, **bzero**() does nothing.
            
        - 함수 설명
            - void *s를 n만큼 0으로 초기화해준다.
            - **code**
                
                ```c
                void	ft_bzero(void *s, size_t n)
                {
                	size_t	i;
                
                	i = 0;
                	while (i < n)
                	{
                		*(unsigned char *)(s + i) = 0;
                		i++;
                	}
                }
                ```
                
                - s가 0일 경우 segfault가 발생해야 한다. 따라서 따로 널가드를 해주지 않았다.
    - ft_calloc
        - man page
            
            **SYNOPSIS**
            #include <stdlib.h>
            
            ```c
             void *
             **calloc**(size_t count, size_t size);
            ```
            
            **DESCRIPTION**
            The malloc(), **calloc**(), valloc(), realloc(), and reallocf() functions allocate memory.  The allocated memory is aligned such that it can be used for any data type, including AltiVec- and SSE-related types.  The aligned_alloc() function allocates memory with the requested alignment.  The free() function frees allocations that were created via the preceding allocation functions.
            
            **RETURN VALUES**
            If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and aligned_alloc() functions return a pointer to allocated memory.  If there is an error, they return a NULL pointer and set errno to ENOMEM.
            
        - 함수 설명
            - `size * count` 만큼의 공간을 할당한 후 0으로 초기화해준다.
            - 리턴값:  할당된 메모리 주소값
            - **code**
                
                ```c
                void	*ft_calloc(size_t count, size_t size)
                {
                	void	*ret;
                
                	ret = malloc(count * size * sizeof(char));
                	if (!ret)
                		return (NULL);
                	ft_bzero(ret, count * size);
                	return (ret);
                }
                ```
                
    - ft_isalnum
        - man page
            
            **SYNOPSIS**
            #include <ctype.h>
            
            ```c
             int
             **isalnum**(int c);
            ```
            
            **DESCRIPTION**
            The **isalnum**() function tests for any character for which **isalpha**(3) or **isdigit**(3) is true.  The value of the argument must be representable as an unsigned char or the value of EOF.
            
            **RETURN VALUES**
            The **isalnum**() function returns zero if the character tests false and returns non-zero if the character tests true.
            
        - code
            
            ```c
            int	ft_isalnum(int c)
            {
            	return (ft_isalpha(c) || ft_isdigit(c));
            }
            ```
            
    - ft_isalpha
        - man page
            
            SYNOPSIS
            #include <ctype.h>
            
            ```c
             int
             **isalpha**(int c);
            ```
            
            DESCRIPTION
            The isalpha() function tests for any character for which isupper(3) or islower(3) is true.  The value of the argument must be representable as an unsigned char or the value of EOF.
            
        - code
            
            ```c
            int	ft_isalpha(int c)
            {
            	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
            }
            ```
            
    - ft_isascii
        - man page
            
            **SYNOPSIS**
            #include <ctype.h>
            
            ```c
             int
             **isascii**(int c);
            ```
            
            **DESCRIPTION**
            The isascii() function tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.
            
        - code
            
            ```c
            int	ft_isascii(int c)
            {
            	return (0 <= c && c <= 127);
            }
            ```
            
    - ft_isdigit
        - man page
            
            **SYNOPSIS**
            #include <ctype.h>
            
            ```c
             int
             **isdigit**(int c);
            ```
            
            **DESCRIPTION**
            The **isdigit**() function tests for a decimal digit character.
            
            **RETURN VALUES**
            The **isdigit**() and **isnumber**() functions return zero if the character tests false and return non-zero if the character tests true.
            
        - code
            
            ```c
            int	ft_isdigit(int c)
            {
            	return ('0' <= c && c <= '9');
            }
            ```
            
    - ft_isprint
        - man page
            
            **SYNOPSIS**
            #include <ctype.h>
            
            ```c
             int
             **isprint**(int c);
            ```
            
            **DESCRIPTION**
            The **isprint**() function tests for any printing character, including space (` ').  The value of the argument must be representable as an unsigned char or the value of EOF.
            
            **RETURN VALUES**
            The **isprint**() function returns zero if the character tests false and returns non-zero if the character tests true.
            
        - code
            
            ```c
            int	ft_isprint(int c)
            {
            	return (32 <= c && c <= 126);
            }
            ```
            
    - ft_memchr
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             void *
             **memchr**(const void *s, int c, size_t n);
            ```
            
            **DESCRIPTION**
            The **memchr**() function locates the first occurrence of c (converted to an unsigned char) in string s.
            
            **RETURN VALUES**
            The **memchr**() function returns a pointer to the byte located, or NULL if no such byte exists within n bytes.
            
        - 함수 설명
            - s에서 n만큼까지만 이동하면서 c를 찾는다.
            - 리턴값
                - c가 있다면 ⇒ (**unsigned char ***)해당 포인터를 리턴
                - 없다면 ⇒ `NULL` 리턴
            - **code**
                
                ```c
                void	*ft_memchr(const void *s, int c, size_t n)
                {
                	unsigned char	*ret;
                
                	ret = (unsigned char *)s;
                	while (n--)
                	{
                		if (*ret == (unsigned char)c)
                			return (ret);
                		else
                			ret++;
                	}
                	return (0);
                }
                ```
                
    - ft_memcmp
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             int
             **memcmp**(const void *s1, const void *s2, size_t n);
            ```
            
            **DESCRIPTION**
            The **memcmp**() function compares byte string s1 against byte string s2.  Both strings are assumed to be n bytes long.
            
            **RETURN VALUES**
            The **memcmp**() function returns zero if the two strings are identical, otherwise returns the difference between the first two differing bytes (treated as unsigned char values, so that `\\200` is greater than \0', for example).  Zero-length strings are always identical.  This behavior is not required by C and portable code should only depend on the sign of the returned value.
            
        - 함수 설명
            - n 동안 s1과 s2의 내용을 비교하는 함수
            - 리턴값
                - 내용이 같다면 ⇒ 0
                - 다르다면 ⇒ unsigned char형으로 `*s1 - *s2` 리턴
            - **code**
                
                ```c
                int	ft_memcmp(const void *s1, const void *s2, size_t n)
                {
                	unsigned char	*p1;
                	unsigned char	*p2;
                
                	p1 = (unsigned char *)s1;
                	p2 = (unsigned char *)s2;
                	while (n--)
                	{
                		if (*p1 != *p2)
                			return (*p1 - *p2);
                		p1++;
                		p2++;
                	}
                	return (0);
                }
                ```
                
    - ft_memcpy
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             void *
             **memcpy**(void *restrict dst, const void *restrict src, size_t n);
            ```
            
            **DESCRIPTION**
            The **memcpy**() function copies n bytes from memory area src to memory area dst.  If dst and src overlap, behavior is undefined.
            Applications in which dst and src might overlap should use memmove(3) instead.
            
            **RETURN VALUES**
            The **memcpy**() function returns the original value of dst.
            
        - 함수 설명
            - src를 dst로 n만큼 복사하는 함수
            - dst와 src의 주소가 겹칠 경우 ⇒ undefined behavior
                
                이럴 경우, **memmove**를 사용한다.
                
            - 리턴값
                - dst의 주소값 리턴
                - dst와 src 모두 `NULL`일 경우 ⇒ `NULL` 리턴
            - **code**
                
                ```c
                void	*ft_memcpy(void *dst, const void *src, size_t n)
                {
                	size_t	i;
                
                	if (!dst && !src)
                		return (0);
                	i = 0;
                	while (i < n)
                	{
                		*(char *)(dst + i) = *(char *)(src + i);
                		i++;
                	}
                	return (dst);
                }
                ```
                
    - ft_memmove
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             void *
             **memmove**(void *dst, const void *src, size_t len);
            ```
            
            **DESCRIPTION**
            The **memmove**() function copies len bytes from string src to string dst.  
            
            The two strings may overlap; the copy is always done in a non-destructive manner.
            
            **RETURN VALUES**
            The **memmove**() function returns the original value of dst.
            
        - 함수 설명
            - dst와 src가 overlap이 될 경우 memcpy 대신 사용할 수 있는 함수
            - memcpy에 비해 속도는 느리다.
            - 리턴값: memcpy와 동일
            - **code**
                
                ```c
                void	*ft_memmove(void *dst, const void *src, size_t len)
                {
                	size_t	i;
                	char	*dst_c;
                
                	if (!dst && !src)
                		return (NULL);
                	i = 0;
                	dst_c = (char *)dst;
                	if (dst > src)
                	{
                		while (len--)
                			*(dst_c + len) = *(char *)(src + len);
                	}
                	else
                	{
                		while (len--)
                		{
                			*dst_c++ = *(char *)src++;
                		}
                	}
                	return (dst);
                }
                ```
                
                - `!dst || !src` 에서 `!dst && !src` 로 바꿔줌.(unit-test)
    - ft_memset
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             void *
             **memset**(void *b, int c, size_t len);
            ```
            
            **DESCRIPTION**
            The **memset**() function writes len bytes of value c (converted to an unsigned char) to the string b.
            
            **RETURN VALUES**
            The **memset**() function returns its first argument.
            
        - 함수 설명
            - b를 n만큼 c로 초기화하는 함수
            - 리턴값: void *b
            - **code**
                
                ```c
                void	*ft_memset(void *b, int c, size_t len)
                {
                	size_t			i;
                	unsigned char	*ret;
                
                	ret = (unsigned char *)b;
                	i = 0;
                	while (i < len)
                	{
                		ret[i] = (unsigned char)c;
                		i++;
                	}
                	return (b);
                }
                ```
                
                - void *b가 NULL일 경우 segfault가 나와야해서 아무것도 처리해주지않음.
    - ft_strchr
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             char *
             **strchr**(const char *s, int c);
            ```
            
            **DESCRIPTION**
            The **strchr**() function locates the first occurrence of c (converted to a char) in the string pointed to by s.  
            
            The terminating null character is considered to be part of the string; 
            
            therefore if c is `\\0', the functions locate the terminating`\0'.
            
            **RETURN VALUES**
            The functions **strchr**() return a pointer to the located character, or NULL if the character does not appear in the string.
            
        
        - 함수 설명
            - 문자열 내에 원하는 문자가 있는지 검사하는 함수
            - 리턴값
                - 첫 번째 매개변수 s의 인덱스를 검사하면서 c가 있다면
                    
                    ⇒ **char ***형으로 해당 포인터를 리턴
                    
                - 없다면 ⇒ `NULL` 리턴
            - code
                
                ```c
                char	*ft_strchr(const char *s, int c)
                {
                	while (*s)
                	{
                		if (*s == (char)c)
                			return ((char *)s);
                		++s;
                	}
                	if (*s == (char)c)
                		return ((char *)s);
                	return (NULL);
                }
                ```
                
    - ft_strdup
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             char *
             **strdup**(const char *s1);
            ```
            
            **DESCRIPTION**
            The **strdup**() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The
            pointer may subsequently be used as an argument to the function free(3).
            
             If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
            
        
        - 함수 설명
            - s1와 동일한 배열을 생성하는 함수
            - 리턴값: 생성한 배열의 주소값
            - **code**
                
                ```c
                char	*ft_strdup(const char *s1)
                {
                	size_t	len;
                	size_t	i;
                	char	*ret;
                
                	len = ft_strlen(s1);
                	ret = malloc(sizeof(char) * (len + 1));
                	if (!ret)
                		return (NULL);
                	i = 0;
                	while (i < len)
                	{
                		ret[i] = s1[i];
                		i++;
                	}
                	ret[i] = '\0';
                	return (ret);
                }
                ```
                
    - ft_strlcat
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             size_t
             **strlcat**(char * restrict dst, const char * restrict src, size_t dstsize);
            ```
            
            **DESCRIPTION**
            The **strlcpy**() and **strlcat**() functions copy and concatenate strings with the same input parameters and output result as snprintf(3).
            
            They are designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3).
            
            **strlcpy**() and **strlcat**() take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NULL should be included in dstsize.
            
            **strlcat**() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters.  It will then NUL-
            terminate, unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means
            that either dstsize is incorrect or that dst is not a proper string).
            
            If the src and dst strings overlap, the behavior is undefined.
            
            **RETURN VALUES**
            Besides quibbles over the return type (size_t versus int) and signal handler safety (snprintf(3) is not entirely safe on some systems), the following two are equivalent:
            
            ```c
                   n = strlcpy(dst, src, len);
                   n = snprintf(dst, len, "%s", src);
            ```
            
            Like snprintf(3), the **strlcpy**() and **strlcat**() functions return the total length of the string they tried to create.  For **strlcpy**()
             that means the length of src.  For **strlcat**() that means the initial length of dst plus the length of src.
             If the return value is >= dstsize, the output string has been truncated.  It is the caller's responsibility to handle this.
            
        
        - 함수 설명
            - dst의 맨 뒤에 src를 dstsize만큼 붙이는 함수
            - dstsize ≤ (dst 길이)
                - 문자열을 붙이지 않음
                - 리턴값: `strlen(src) + dstsize`
            - dstsize > (dst 길이)
                - size - 1만큼 src를 붙이고 마지막에 '\0'값을 넣어줌
                - 리턴값: `strlen(src) + strlen(dst)`
            - **code**
                
                ```c
                size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
                {
                	size_t	dst_len;
                	size_t	src_len;
                
                	dst_len = ft_strlen(dst);
                	src_len = ft_strlen(src);
                	if (dstsize < dst_len)
                		return (src_len + dstsize);
                	ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
                	return (src_len + dst_len);
                }
                ```
                
    - ft_strlcpy
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             size_t
             strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
            ```
            
            **DESCRIPTION**
            The **strlcpy**() and **strlcat**() functions copy and concatenate strings with the same input parameters and output result as snprintf(3).
            
            They are designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3).
            
            **strlcpy**() and **strlcat**() take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for the NULL should be included in dstsize.
            
            **strlcpy**() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.
            
            **RETURN VALUES**
            Besides quibbles over the return type (size_t versus int) and signal handler safety (snprintf(3) is not entirely safe on some systems), the following two are equivalent:
            
            ```c
                   n = strlcpy(dst, src, len);
                   n = snprintf(dst, len, "%s", src);
            ```
            
            Like snprintf(3), the **strlcpy**() and **strlcat**() functions return the total length of the string they tried to create.  For **strlcpy**()
             that means the length of src.  For **strlcat**() that means the initial length of dst plus the length of src.
             If the return value is >= dstsize, the output string has been truncated.  It is the caller's responsibility to handle this.
            
        - 함수 설명
            - dst 안에 src를 복사해주는 함수
            - `dstsize`: src의 길이 이하일 때 사용됨
            - src의 `\0` 값을 만나거나 `dstsize - 1` 만큼 복사되면 복사를 중지한다.
            - `-1` 이 붙은 이유: 복사를 진행한 후 마지막에 `\0` 을 넣어주기 위해서
                
                ➡️ `strcpy` 나 `strncpy` 보다 안정성이 있다.
                
            - 리턴값: 복사하려했던 문자열의 길이 = `src` 의 길이
            - **code**
                
                ```c
                size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
                {
                	size_t	i;
                	size_t	ret;
                
                	i = 0;
                	ret = ft_strlen(src);
                	if (dstsize == 0)
                		return (ret);
                	while (src[i] && i < (dstsize - 1))
                	{
                		dst[i] = src[i];
                		i++;
                	}
                	dst[i] = 0;
                	return (ret);
                }
                ```
                
    - ft_strlen
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             size_t
             **strlen**(const char *s);
            ```
            
            **DESCRIPTION**
            The **strlen**() function computes the length of the string s.  The **strnlen**() function attempts to compute the length of s, but never scans beyond the first maxlen bytes of s.
            
            **RETURN VALUES**
            The **strlen**() function returns the number of characters that precede the terminating NUL character.  The strnlen() function returns
            either the same result as strlen() or maxlen, whichever is smaller.
            
        - code
            
            ```c
            size_t	ft_strlen(const char *s)
            {
            	size_t	i;
            
            	i = 0;
            	while (s[i])
            		i++;
            	return (i);
            }
            ```
            
    - ft_strncmp
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
            int
            **strncmp**(const char *s1, const char *s2, size_t n);
            ```
            
            **DESCRIPTION**
            
            The strcmp() and strncmp() functions lexicographically compare the null-terminated strings s1 and s2.
            
            The strncmp() function compares not more than n characters.  Because strncmp() is designed for comparing strings rather than
             binary data, characters that appear after a `\\0' character are not compared.
            
            **RETURN VALUES**
            The strcmp() and strncmp() functions return an integer greater than, equal to, or less than 0, according as the string s1 is
            greater than, equal to, or less than the string s2.  The comparison is done using unsigned characters, so that `\\200' is greater than`\0'.
            
        - 함수 설명
            - s1, s2 두 문자열의 내용을 1바이트씩 unsigned char로 크고 작음을 비교하는 함수
                
                [https://www.it-note.kr/75](https://www.it-note.kr/75)
                
            - `n` : 검사할 범위
            - 리턴값
                - 계속 비교하다가 두 문자열이 다르다면
                    
                    ⇒ s1 - s2 리턴
                    
                - 두 문자열이 완전히 같다면
                    
                    ⇒ 0 리턴
                    
            - **code**
                
                ```c
                int	ft_strncmp(const char *s1, const char *s2, size_t n)
                {
                	size_t			i;
                
                	i = 0;
                	while (s1[i] && s2[i] && i < n)
                	{
                		if (s1[i] != s2[i])
                			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                		++i;
                	}
                	if (i < n)
                		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                	return (0);
                }
                ```
                
    - ft_strnstr
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             char *
             **strnstr**(const char *haystack, const char *needle, size_t len);
            ```
            
            **DESCRIPTION**
            The strnstr() function locates the first occurrence of the null-terminated string needle in the string haystack, where not more
             than len characters are searched.  Characters that appear after a `\\0' character are not searched.  Since the strnstr() function
             is a FreeBSD specific API, it should only be used when portability is not a concern.
            
            **RETURN VALUES**
            If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is returned; otherwise a pointer to
            the first character of the first occurrence of needle is returned.
            
        - 함수 설명
            - 문자열 `haystack` 에서 길이 `len` 안에 `needle` 이 있는지 검사하는 함수
            - 리턴값
                - `needle` 이 `NULL` 이라면 ⇒ `haystack` 반환
                - `needle` 을 찾았다면 ⇒ 찾은 지점의 주소를 반환
                - 못 찾았다면 ⇒ `NULL` 반환
            - **code**
                
                ```c
                char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
                {
                	size_t	i;
                	size_t	j;
                
                	i = 0;
                	if (!(*needle))
                		return ((char *)haystack);
                	while (i < len && haystack[i])
                	{
                		j = 0;
                		while (haystack[i + j] == needle[j] && needle[j] && (i + j) < len)
                			j++;
                		if (!needle[j])
                			return ((char *)(haystack + i));
                		i++;
                	}
                	return (NULL);
                }
                ```
                
    - ft_strrchr
        - man page
            
            **SYNOPSIS**
            #include <string.h>
            
            ```c
             char *
             **strrchr**(const char *s, int c);
            ```
            
            **DESCRIPTION**
            The **strchr**() function locates the first occurrence of c (converted to a char) in the string pointed to by s.  The terminating null
            character is considered to be part of the string; therefore if c is `\\0` , the function locate the terminating `\0'`
            
            The **strrchr**() function is identical to strchr(), except it locates the last occurrence of c.
            
            **RETURN VALUES**
            The functions **strchr**() and **strrchr**() return a pointer to the located character, or NULL if the character does not appear in the
            string.
            
        - 함수 설명
            - `strchr`과 동일하게 작동. 단, 문자열의 뒤에서부터 검사.
            - 리턴값
                - 첫 번째 매개변수 `s` 의 인덱스를 검사하면서 `c`가 있다면
                    
                    ⇒ 해당 포인터를 리턴
                    
                - 없다면 ⇒ `NULL` 리턴
            - **code**
                
                ```c
                char	*ft_strrchr(const char *s, int c)
                {
                	char		*end;
                	char		*prev;
                
                	prev = 0;
                	end = (char *)s;
                	if (c == 0)
                		return ((char *)(s + ft_strlen(s)));
                	while (1)
                	{
                		end = ft_strchr(end, c);
                		if (!end)
                			return (prev);
                		prev = end;
                		++end;
                	}
                	return (NULL);
                }
                ```
                
                - `c == NULL` 의 경우 s의 끝에 있는 null을 리턴해준다.
    - ft_tolower
        - man page
            
            **SYNOPSIS**
            #include <ctype.h>
            
            ```c
             int
             **tolower**(int c);
            ```
            
            **DESCRIPTION**
            The tolower() function converts an upper-case letter to the corresponding lower-case letter.  The argument must be representable
            as an unsigned char or the value of EOF.
            
            Although the tolower() function uses the current locale, the tolower_l() function may be passed a locale directly. See xlocale(3) for more information.
            
            **RETURN VALUES**
            If the argument is an upper-case letter, the tolower() function returns the corresponding lower-case letter if there is one; oth-
            erwise, the argument is returned unchanged.
            
        - 함수 설명
            - 대문자 C를 대응하는 소문자로 변환하는 함수
            - 리턴값: 변환된 문자. 문자 C에 대응하는 대문자가 없으면 함수는 C를 변경하지 않고 리턴
            - code
                
                ```c
                int	ft_tolower(int c)
                {
                	if ('A' <= c && c <= 'Z')
                		return (c + ('a' - 'A'));
                	else
                		return (c);
                }
                ```
                
    - ft_toupper
        - man page
            
            **SYNOPSIS**
            #include <ctype.h>
            
            ```c
             int
             **toupper**(int c);
            ```
            
            **DESCRIPTION**
            The **toupper**() function converts a lower-case letter to the corresponding upper-case letter.  The argument must be representable as
            an unsigned char or the value of EOF.
            
             Although the toupper() function uses the current locale, the toupper_l() function may be passed a locale directly. See xlocale(3)
             for more information.
            
            **RETURN VALUES**
            If the argument is a lower-case letter, the toupper() function returns the corresponding upper-case letter if there is one; other-
            wise, the argument is returned unchanged.
            
        - 함수 설명
            - 소문자 c를 대응하는 대문자로 변환하는 함수
            - 리턴값: 변환된 문자. 문자 *c*에 대응하는 소문자가 없으면 함수는 *c*를 변경하지 않고 리턴
            - **code**
                
                ```c
                int	ft_toupper(int c)
                {
                	if ('a' <= c && c <= 'z')
                		return (c - ('a' - 'A'));
                	else
                		return (c);
                }
                ```
                
- Part2: Additional functions
    - ft_substr
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a substring from the string ’s’.
            The substring begins at index ’start’ and is of maximum size ’len’.
            
            ---
            
            `len + 1` 만큼의 배열 할당 후 `s + start` 부터 len만큼/s가 끝날 때까지 삽입 후 마지막에 null을 붙여서 리턴한다.
            
        - code
            
            ```c
            static size_t	check_len(size_t len, char const *s)
            {
            	size_t	s_len;
            
            	s_len = ft_strlen(s);
            	if (s_len < len)
            		return (s_len);
            	return (len);
            }
            
            char	*ft_substr(char const *s, unsigned int start, size_t len)
            {
            	unsigned int	i;
            	size_t			j;
            	char			*ret;
            
            	if (!s)
            		return (NULL);
            	if (start >= ft_strlen(s))
            		return (ft_strdup(""));
            	len = check_len(len, s);
            	ret = malloc(sizeof(char) * (len + 1));
            	if (!ret)
            		return (NULL);
            	i = start;
            	j = 0;
            	while (j < len)
            	{
            		if (!(s[i]))
            			break ;
            		ret[j++] = s[i++];
            	}
            	ret[j] = '\0';
            	return (ret);
            }
            ```
            
    - ft_strjoin
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
            
        - code
            
            ```c
            char	*ft_strjoin(char const *s1, char const *s2)
            {
            	char	*ret;
            	size_t	len_s1;
            	size_t	len_s2;
            
            	if (!s1 || !s2)
            		return (NULL);
            	len_s1 = ft_strlen((char *)s1);
            	len_s2 = ft_strlen((char *)s2);
            	ret = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
            	if (!ret)
            		return (NULL);
            	ft_strlcpy(ret, (char *)s1, len_s1 + 1);
            	ft_strlcat(ret, (char *)s2, len_s1 + len_s2 + 1);
            	return (ret);
            }
            ```
            
    - ft_strtrim
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
            
        - code
            
            ```c
            char	*ft_strtrim(char const *s1, char const *set)
            {
            	char const	*start;
            	char const	*end;
            	char		*ret;
            
            	if (!s1)
            		return (0);
            	if (!set)
            		return (ft_strdup(s1));
            	start = s1;
            	end = s1 + ft_strlen(s1);
            	while (*start && ft_strchr(set, *start))
            		++start;
            	while (start < end && ft_strchr(set, *(end - 1)))
            		--end;
            	ret = (char *)malloc(sizeof(char) * (end - start + 1));
            	if (!ret)
            		return (0);
            	ft_strlcpy(ret, start, end - start + 1);
            	return (ret);
            }
            ```
            
    - ft_split
        - 함수 설명
            
            Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.  
            
            The array must beended by a NULL pointer.
            
        - code
            
            ```c
            static char	**ft_malloc_ret(char *s, char c)
            {
            	size_t	cnt;
            	char	**ret;
            
            	cnt = 0;
            	if (!s)
            		return (NULL);
            	while (*s)
            	{
            		if (*s != c)
            		{
            			cnt++;
            			while (*s != c && *s)
            				s++;
            		}
            		else
            			s++;
            	}
            	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
            	if (!ret)
            		return (NULL);
            	return (ret);
            }
            
            static char	*ft_malloc_ret_n(char *str, char *start, char *end)
            {
            	int	i;
            
            	str = (char *)malloc(end - start + 1);
            	if (!str)
            		return (NULL);
            	i = -1;
            	while (++i < end - start)
            		str[i] = start[i];
            	str[i] = 0;
            	return (str);
            }
            
            static void	*free_all(char **str, size_t l)
            {
            	size_t	i;
            
            	i = 0;
            	while (str[i] && i < l)
            	{
            		free(str[i]);
            		i++;
            	}
            	free(str);
            	return (NULL);
            }
            
            char	**ft_split(char const *s, char c)
            {
            	char	**ret;
            	char	*start;
            	size_t	i;
            
            	ret = ft_malloc_ret((char *)s, c);
            	if (!ret)
            		return (NULL);
            	i = 0;
            	while (*s)
            	{
            		if (*s != c)
            		{
            			start = (char *)s;
            			while (*s && *s != c)
            				s++;
            			ret[i] = ft_malloc_ret_n(ret[i], start, (char *)s);
            			if (!ret[i++])
            				return (free_all(ret, i));
            		}
            		else
            			s++;
            	}
            	ret[i] = 0;
            	return (ret);
            }
            ```
            
    - ft_itoa
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a string representing the integer received as an argument.
            
            Negative numbers must be handled.
            
        - code
            
            ```c
            static int	ft_cnt_len(int n)
            {
            	int	cnt;
            
            	cnt = 0;
            	if (n <= 0)
            	{
            		cnt++;
            		n *= -1;
            	}
            	while (n)
            	{
            		n /= 10;
            		cnt++;
            	}
            	return (cnt);
            }
            
            static char	*ft_ntoret(char *ret, long n, int len)
            {
            	int	cnt;
            
            	cnt = 0;
            	if (n < 0)
            	{
            		n *= -1;
            		ret[0] = '-';
            		cnt++;
            	}
            	while (len > cnt)
            	{
            		ret[len - 1] = (n % 10) + '0';
            		n /= 10;
            		len--;
            	}
            	return (ret);
            }
            
            char	*ft_itoa(int n)
            {
            	char	*ret;
            	int		len;
            
            	len = ft_cnt_len(n);
            	ret = (char *)malloc(sizeof(char) * (len + 1));
            	if (!ret)
            		return (NULL);
            	ret = ft_ntoret(ret, (long)n, len);
            	ret[len] = 0;
            	return (ret);
            }
            ```
            
    - ft_strieri
        - 함수 설명
            
            Applies the function f to each character of the string passed as argument, and passing its index as first argument.  
            
            Each character is passed by address to f to be modified if necessary
            
        - code
            
            ```c
            void	ft_striteri(char *s, void (*f)(unsigned int, char *))
            {
            	unsigned int	i;
            
            	if (!s || !f)
            		return ;
            	i = 0;
            	while (s[i])
            	{
            		f(i, &s[i]);
            		i++;
            	}
            }
            ```
            
    - ft_strmapi
        - 함수 설명
            
            Applies the function ’f’ to each character of the string ’s’ , and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.
            
        - code
            
            ```c
            char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
            {
            	char			*ret;
            	unsigned int	i;
            
            	if (!s || !f)
            		return (NULL);
            	ret = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
            	if (!ret)
            		return (NULL);
            	i = 0;
            	while (s[i])
            	{
            		ret[i] = f(i, s[i]);
            		i++;
            	}
            	ret[i] = 0;
            	return (ret);
            }
            ```
            
    - ft_putchar_fd
        - 함수 설명
            
            Outputs the character ’c’ to the given file descriptor.
            
        - code
            
            ```c
            void	ft_putchar_fd(char c, int fd)
            {
            	if (fd < 0)
            		return ;
            	write(fd, &c, 1);
            }
            ```
            
    - ft_putstr_fd
        - 함수 설명
            
            Outputs the string ’s’ to the given file descriptor.
            
        - code
            
            ```c
            void	ft_putstr_fd(char *s, int fd)
            {
            	size_t	len;
            
            	if (fd < 0 || !s)
            		return ;
            	len = ft_strlen(s);
            	write(fd, s, len);
            }
            ```
            
    - ft_putendl_fd
        - 함수 설명
            
            Outputs the string ’s’ to the given file descriptor, followed by a newline.
            
        - code
            
            ```c
            void	ft_putendl_fd(char *s, int fd)
            {
            	if (!s || fd < 0)
            		return ;
            	ft_putstr_fd(s, fd);
            	ft_putchar_fd('\n', fd);
            }
            ```
            
    - ft_putnbr_fd
        - 함수 설명
            
            Outputs the integer ’n’ to the given file descriptor.
            
        - code
            
            ```c
            void	ft_putnbr_fd(int n, int fd)
            {
            	if (fd < 0)
            		return ;
            	if (n == -2147483648)
            	{
            		ft_putstr_fd("-2147483648", fd);
            		return ;
            	}
            	else if (n < 0)
            	{
            		n *= -1;
            		ft_putchar_fd('-', fd);
            	}
            	if (n >= 10)
            	{
            		ft_putnbr_fd(n / 10, fd);
            		ft_putchar_fd((n % 10) + '0', fd);
            	}
            	else
            		ft_putchar_fd((n % 10) + '0', fd);
            }
            ```
            
- Bonus
    - struct t_list
        
        ```c
        typedef struct s_list
        {
        	void			*content;
        	struct s_list	*next;
        }	t_list;
        ```
        
    - ft_lstnew
        - 함수 설명
            
            Allocates (with malloc(3)) and returns a new element.  
            
            The variable `content` is initialized with the value of the parameter `content`.  
            
            The variable `next` is initialized to NULL.
            
            ⇒ lst에서 새로운 노드를 추가하는 함수.
            
        - code
            
            ```c
            t_list	*ft_lstnew(void *content)
            {
            	t_list	*ret;
            
            	ret = (t_list *)malloc(sizeof(t_list));
            	if (!ret)
            		return (NULL);
            	ret -> content = content;
            	ret -> next = NULL;
            	return (ret);
            }
            ```
            
    - ft_lstadd_front
        - 함수 설명
            
            Adds the element `new` at the beginning of the list.
            
            ⇒ lst의 맨 앞에 new를 추가하는 함수
            
        - code
            
            ```c
            void	ft_lstadd_front(t_list **lst, t_list *new)
            {
            	new -> next = *lst;
            	*lst = new;
            }
            ```
            
    - ft_lstsize
        - 함수 설명
            
            Counts the number of elements in a list.
            
            ⇒ lst에 있는 노드의 개수를 세는 함수
            
        - code
            
            ```c
            int	ft_lstsize(t_list *lst)
            {
            	int	i;
            
            	i = 0;
            	while (lst)
            	{
            		i++;
            		lst = lst -> next;
            	}
            	return (i);
            }
            ```
            
    - ft_lstlast
        - 함수 설명
            
            Returns the last element of the list.
            
            ⇒ lst의 마지막 노드를 리턴하는 함수
            
        - code
            
            ```c
            t_list	*ft_lstlast(t_list *lst)
            {
            	if (!lst)
            		return (NULL);
            	while (lst -> next)
            	{
            		lst = lst -> next;
            	}
            	return (lst);
            }
            ```
            
    - ft_lstadd_back
        - 함수 설명
            
            Adds the element `new` at the end of the list.
            
            ⇒ lst의 맨 뒤에 new를 추가하는 함수
            
        - code
            
            ```c
            void	ft_lstadd_back(t_list **lst, t_list *new)
            {
            	t_list	*back;
            
            	if (!lst || !new)
            		return ;
            	back = *lst;
            	if (!(*lst))
            	{
            		*lst = new;
            		return ;
            	}
            	while (back->next)
            		back = back->next;
            	back->next = new;
            }
            ```
            
    - ft_lstdelone
        - 함수 설명
            
            Takes as a parameter an element and frees the memory of the element’s content using the function `del` given as a parameter and free the element.
            
            The memory of `next` must not be freed.
            
            ⇒ del 함수를 이용해 lst의 content를 없애고 free해주는 함수
            
        - code
            
            ```c
            void	ft_lstdelone(t_list *lst, void (*del)(void *))
            {
            	if (!lst || !del)
            		return ;
            	del(lst -> content);
            	free(lst);
            }
            ```
            
    - ft_lstclear
        - 함수 설명
            
            Deletes and frees the given element and every successor of that element, using the function `del` and free(3).
            
            Finally, the pointer to the list must be set to NULL.
            
            ⇒ del 함수를 이용해 lst의 content를 모두 지우고 free해주는 함수
            
        - code
            
            ```c
            void	ft_lstclear(t_list **lst, void (*del)(void *))
            {
            	t_list	*tmp;
            
            	if (!lst || !del)
            		return ;
            	while (*lst)
            	{
            		tmp = (*lst)->next;
            		del((*lst)->content);
            		free(*lst);
            		(*lst) = tmp;
            	}
            	*lst = 0;
            }
            ```
            
    - ft_lstiter
        - 함수 설명
            
            Iterates the list `lst` and applies the function ’f’ to the content of each element.
            
            ⇒ 모든 lst에 대하여 f 함수를 적용시키는 함수
            
        - code
            
            ```c
            void	ft_lstiter(t_list *lst, void (*f)(void *))
            {
            	if (!lst || !f)
            		return ;
            	while (lst)
            	{
            		f(lst->content);
            		lst = lst->next;
            	}
            }
            ```
            
    - ft_lstmapi
        - 함수 설명
            
            Iterates the list `lst` and applies the function `f` to the content of each element.  
            
            Creates a new list resulting of the successive applications of the function `f`  
            
            The `del` function is used to delete the content of an element if needed.
            
            ⇒ 새로운 리스트를 생성하여 lst의 모든 content에 f 함수를 적용시켜 넣는 함수.
            
            실패 시 del 함수를 이용해 없앰, free 해주어야 한다. 
            
        - code
            
            ```c
            char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
            {
            	char			*ret;
            	unsigned int	i;
            
            	if (!s || !f)
            		return (NULL);
            	ret = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
            	if (!ret)
            		return (NULL);
            	i = 0;
            	while (s[i])
            	{
            		ret[i] = f(i, s[i]);
            		i++;
            	}
            	ret[i] = 0;
            	return (ret);
            }
            ```
            
- Makefile
    - `Makefile`은 다음과 같은 구조를 가진다.
        
        > -목적파일(Target) : 명령어가 수행되어 나온 결과를 저장할 파일
        > 
        > 
        > -의존성(Dependency) : 목적파일을 만들기 위해 필요한 재료 
        > 
        > -명령어(Command) : 실행 되어야 할 명령어들 
        > 
        > -매크로(macro) : 코드를 단순화 시키기 위한 방법
        > 
    - **Make에서 룰이 실행되는 조건**
        - 타겟 파일이 프로젝트 폴더 안에 없을 때
        - Prerequisites(전제 조건)에 변경점이 발생했을 때
    - `$()` 를 사용하면 정의되어 있는 변수나 함수를 불러올 수 있다.
        
        ```c
        SRC = file_a.c file_b.c file_c.c
        NAME = a.out
        
        $(NAME): $(SRC)
                 gcc $(SRC)
        ```
        
        - 패턴 룰 적용하기
            
            ```c
            OBJ = file_a.o file_b.o file_c.o
            NAME = a.out
            
            %.o : %.c
                  gcc $< -o $@
            
            $(NAME): $(OBJ)
                     gcc $(OBJ)
            ```
            
        
        > 💡 와일드카드 문자인 `*` 를 make에서도 지원하지만 잘 사용하지 않고 `%` 를 사용한다 ⇒ [참고](https://www.gnu.org/software/make/manual/html_node/Wildcard-Pitfall.html#Wildcard-Pitfall)
        > 
    - code
        
        ```makefile
        NAME = libft.a
        FILES = ft_strlen \
        	ft_strlcpy \
        	ft_strlcat \
        	ft_strchr \
        	ft_strrchr \
        	ft_strnstr \
        	ft_strncmp \
        	ft_atoi \
        	ft_isalpha \
        	ft_isdigit \
        	ft_isalnum \
        	ft_isascii \
        	ft_isprint \
        	ft_toupper \
        	ft_tolower \
        	ft_memset \
        	ft_bzero \
        	ft_memcpy \
        	ft_memchr \
        	ft_memmove \
        	ft_memcmp \
        	ft_calloc \
        	ft_strdup \
        	ft_substr \
        	ft_strjoin \
        	ft_strtrim \
        	ft_split \
        	ft_itoa \
        	ft_strmapi \
        	ft_striteri \
        	ft_putchar_fd \
        	ft_putstr_fd \
        	ft_putendl_fd \
        	ft_putnbr_fd
        
        FILES_BONUS = ft_lstadd_back \
        	ft_lstadd_front \
        	ft_lstclear \
        	ft_lstdelone \
        	ft_lstlast \
        	ft_lstnew \
        	ft_lstsize	\
        	ft_lstiter	\
        	ft_lstmap
        
        DIR_SRCS	= ./
        OBJS		= $(addprefix $(DIR_SRCS), $(addsuffix .o, $(FILES)))
        OBJS_BONUS	= $(addprefix $(DIR_SRCS), $(addsuffix .o, $(FILES_BONUS)))
        SRCS		= $(addprefix $(DIR_SRCS), $(addsuffix .c, $(FILES)))
        SRCS_BONUS	= $(addprefix $(DIR_SRCS), $(addsuffix .c, $(FILES_BONUS)))
        
        CC			= gcc
        CFLAGS		= -Wall -Wextra -Werror
        
        AR			= ar crs
        RM			= rm -f
        
        ifdef WITH_BONUS
        	OBJS_FILES = $(OBJS) $(OBJS_BONUS)
        else
        	OBJS_FILES = $(OBJS)
        endif
        
        all:	$(NAME)
        
        $(NAME):	$(OBJS_FILES)
        	$(AR) $(NAME) $(OBJS_FILES)
        
        bonus:
        	@make WITH_BONUS=1 all
        
        clean:
        	$(RM) $(OBJS) $(OBJS_BONUS)
        
        fclean: clean
        	$(RM) $(NAME)
        
        re: fclean all
        
        .PHONY:	all bonus clean fclean re
        ```
        
