/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:37:11 by sneo              #+#    #+#             */
/*   Updated: 2023/09/08 12:37:16 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
// #include <bsd/string.h> //Does not work

int	main(void)
{
	printf("ft_isalpha *********************************\n");
	printf("non-zero: %d\n", isalpha('e'));
	printf("non-zero: %d\n", ft_isalpha('e'));
	printf("zero: %d\n", isalpha('3'));
	printf("zero: %d\n", ft_isalpha('3'));
	printf("ft_isdigit *********************************\n");
	printf("non-zero: %d\n", isdigit('4'));
	printf("non-zero: %d\n", ft_isdigit('4'));
	printf("zero: %d\n", isdigit('w'));
	printf("zero: %d\n", ft_isdigit('w'));
	printf("ft_isalnum *********************************\n");
	printf("non-zero: %d\n", isalnum('e'));
	printf("non-zero: %d\n", ft_isalnum('e'));
	printf("zero: %d\n", isalnum(','));
	printf("zero: %d\n", ft_isalnum(','));
	printf("ft_isascii *********************************\n");
	printf("non-zero: %d\n", isascii('e'));
	printf("non-zero: %d\n", ft_isascii('e'));
	printf("zero: %d\n", isascii(234));
	printf("zero: %d\n", ft_isascii(234));
	printf("ft_isprint *********************************\n");
	printf("non-zero: %d\n", isprint('e'));
	printf("non-zero: %d\n", ft_isprint('e'));
	printf("zero: %d\n", isprint(23));
	printf("zero: %d\n", ft_isprint(23));
	printf("ft_strlen *********************************\n");
	printf("3: %d\n", ft_strlen("hwp"));
	printf("0: %d\n", ft_strlen(""));
	 // Code below cause "terminated by signal SIGSEGV (Address boundary error)"
	 //   even though ft_memset seems correct.
	/*printf("ft_memset *********************************\n");
	char	*s1;
	char	*s2;
	s1 = "abc";
	s2 = "defgh";
	write(1, &s1, 1);
	write(1, "\n", 1);
	write(1, s1, 3);
	write(1, "\n", 1);
	s2 = ft_memset(s1, 65, 2);
	write(1, s2, 2);*/
	printf("ft_memset *********************************\n");
	char	*s1;
	char	*s2;
	s1 = "abc";
	s2 = malloc(4); //Chris used malloc and strcpy to solve the issue.
	s2 = strcpy(s2, s1); //Without malloc and strcpy, s1 and s2 are read-only.
	printf("0: %d\n", memcmp(memset(s2, 65, 2), ft_memset(s2, 65, 2), 2));
	printf("ft_bzero *********************************\n");
	char	*s3;
	s3 = malloc(4);
	s3 = strcpy(s3, s1);
	bzero(s2, 2);
	ft_bzero(s3, 2);
	printf("0: %d\n", memcmp(s2, s3, 3));
	printf("ft_memcpy *********************************\n");
	printf("s3: %s\n", s3);
	printf("s1: %s\n", s1);
	printf("0: %d\n", strcmp(s3, ft_memcpy(s3, s1, 3)));
	printf("ft_memmove *********************************\n");
	printf("s3: %s\n", s3);
	printf("s2: %s\n", s2);
	printf("0: %d\n", strcmp(s3, ft_memmove(s3, s2, 3)));
	// printf("ft_strlcpy *********************************\n");
	// printf("s3: %s\n", s3);
	// printf("s1: %s\n", s2);
	// printf("s1: %s\n", s1);
	// printf("3: %zu\n", strlcpy(s3, s1, 3)); //Need to include libbsd. Don't know how.
	// printf("s3: %s\n", s3);
	// printf("s1: %s\n", s1);
	// printf("3: %zu\n", ft_strlcpy(s2, s1, 3));
	// printf("s2: %s\n", s2);
	// printf("s1: %s\n", s1);
	// printf("ft_strlcat *********************************\n");
	// printf("s3: %s\n", s3);
	// printf("s1: %s\n", s2);
	// printf("s1: %s\n", s1);
	// printf("3: %zu\n", strlcat(s3, s1, 4)); //Need to include libbsd. Don't know how.
	// printf("s3: %s\n", s3);
	// printf("s1: %s\n", s1);
	// printf("3: %zu\n", ft_strlcat(s2, s1, 4));
	// printf("s2: %s\n", s2);
	// printf("s1: %s\n", s1);
	printf("ft_toupper *********************************\n");
	printf("69: %d\n", toupper('e'));
	printf("69: %d\n", ft_toupper('e'));
	printf("51: %d\n", toupper('3'));
	printf("51: %d\n", ft_toupper('3'));
	printf("ft_tolower *********************************\n");
	printf("101: %d\n", tolower('E'));
	printf("101: %d\n", ft_tolower('E'));
	printf("51: %d\n", tolower('3'));
	printf("51: %d\n", ft_tolower('3'));
	printf("ft_strchr *********************************\n");
	printf("101: %s\n", strchr("Each , cup.", 'c'));
	printf("101: %s\n", ft_strchr("Each , cup.", 'c'));
	// printf("51: %s\n", strchr("Each , cup.", 'd')); //Caused: ‘%s’ directive argument is null
	printf("51: %s\n", ft_strchr("Each , cup.", 'd'));
	printf("ft_strrchr *********************************\n");
	printf("101: %s\n", strrchr("Each , cup.", 'c'));
	printf("101: %s\n", ft_strrchr("Each , cup.", 'c'));
	// printf("51: %s\n", strrchr("Each , cup.", 'd')); //Caused: ‘%s’ directive argument is null
	printf("51: %s\n", ft_strrchr("Each , cup.", 'd'));
	// ft_memchr passed Francinette but the following test code caused: './a.out' terminated by signal SIGSEGV (Address boundary error)
	// printf("ft_memchr *********************************\n");
	// char	*s1;
	// char	*s2;
	// size_t	n;
	// int		c;
	// s1 = "abc";
	// s2 = malloc(4); //Chris used malloc and strcpy to solve the issue.
	// s2 = strcpy(s2, s1); //Without malloc and strcpy, s1 and s2 are read-only.
	// n = 2;
	// c = 66;
	// printf("0: %d\n", memcmp(memchr(s2, c, n), ft_memchr(s2, c, n), n));
	printf("ft_strncmp *********************************\n");
	printf("0: %d\n", strncmp("ABC", "ABXY", 2));
	printf("0: %d\n", ft_strncmp("ABC", "ABXY", 2));
	printf("-25: %d\n", strncmp("ABA", "ABZ", 3));
	printf("-25: %d\n", ft_strncmp("ABA", "ABZ", 3));
	printf("7: %d\n", strncmp("ABJ", "ABC", 3));
	printf("7: %d\n", ft_strncmp("ABJ", "ABC", 3));
	printf("ft_memcmp *********************************\n");
	printf("0: %d\n", memcmp("ABC", "ABXY", 2));
	printf("0: %d\n", ft_memcmp("ABC", "ABXY", 2));
	printf("-25: %d\n", memcmp("ABA", "ABZ", 3));
	printf("-25: %d\n", ft_memcmp("ABA", "ABZ", 3));
	printf("7: %d\n", memcmp("ABJ", "ABC", 3));
	printf("7: %d\n", ft_memcmp("ABJ", "ABC", 3));
	printf("ft_strnstr *********************************\n");
	char str[] = "Hey.llo Hello.";
	char to_find[] = "Hello";
	printf("Pointer of haystack: %p\n", &str[8]);
	printf("Pointer of returned value: %p\n", ft_strnstr(str, to_find, 8));
	printf("ft_atoi *********************************\n");
	printf("-322: %d\n", atoi("  	-322"));
	printf("-322: %d\n", ft_atoi("  	-322"));
	printf("0: %d\n", atoi("++---aj322"));
	printf("0: %d\n", ft_atoi("++---aj322"));
	printf("0: %d\n", atoi("  	--+-322"));
	printf("0: %d\n", ft_atoi("  	--+-322"));
	printf("ft_calloc *********************************\n");	
	size_t	nmemb = 2;
	size_t	size = 3;
	printf("calloc gives %s\n", (char *)calloc(nmemb, size));
	printf("ft_calloc gives %s\n", (char *)ft_calloc(nmemb, size));
	printf("ft_strdup *********************************\n");	
	char	*str2 = "hij";
	printf("strdup(str2) gives %s\n", strdup(str2));
	printf("ft_strdup(str2) gives %s\n", ft_strdup(str2));
	printf("ft_substr *********************************\n");
	char	*str3 = "hijkm";
	printf("ijk: %s\n", ft_substr(str3, 1, 3));
	printf("j: %s\n", ft_substr(str3, 2, 1));
	printf(": %s\n", ft_substr(str3, 2, 0));
	printf("ft_strjoin *********************************\n");
	char d[] = "Hello";
	char s[] = " Evaluator";
	printf("%s\n", ft_strjoin(d, s));
	printf("ft_strtrim *********************************\n");
	printf("%s\n", ft_strtrim("bcdef", "bc"));
	printf("%s\n", ft_strtrim("bcde", "efghijk"));
	printf("%s\n", ft_strtrim("bcdef", ""));
	printf("%s\n", ft_strtrim("", "bcd"));
	printf("%s\n", ft_strtrim("", ""));
	printf("ft_split *********************************\n");
	char	**result = ft_split("bcdef ;jlija aljliezlie alie", ' ');
	while (*result)
		printf("%s\n", *result++);
	result = ft_split("bcdef ;jlija aljliezlie alie", 'j');
	while (*result)
		printf("%s\n", *result++);
	printf("ft_itoa *********************************\n");
	printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(0));
	printf("ft_strmapi's testing code is in ft_strmapi.c. **************\n");
	printf("ft_striteri's testing code is in ft_striteri.c. **************\n");
	printf("ft_lstnew, ft_lstadd_front, etc ***************************\n");
	t_list	*lst = ft_lstnew("cde");
	printf("%p\n", lst->content);
	printf("%s\n", (char *)(lst->content));
	printf("%p\n", lst->next);
	t_list	*lst2 = ft_lstnew("pqr");
	ft_lstadd_front(&lst, lst2);
	printf("%s\n", (char *)(lst->content));
	printf("%s\n", (char *)(lst->next->content));
	printf("%d\n", ft_lstsize(lst));
	printf("%s\n", (char *)(ft_lstlast(lst)->content));
	t_list	*lst3 = ft_lstnew("x");
	ft_lstadd_back(&lst, lst3);
	printf("%s\n", (char *)(ft_lstlast(lst)->content));
	// void	ft_del(void *d)
	// {
	// 	free(d);
	// }
	// ft_lstdelone(lst2, &ft_del); //Causes "munmap_chunk(): invalid pointer" and "SIGABRT (Abort)".
	// printf("%s\n", (char *)(lst->content));
	// printf("%s\n", (char *)(lst3->content));
	// printf("%s\n", (char *)(lst2->content));
	// ft_lstclear(&lst, &ft_del); //Causes "munmap_chunk(): invalid pointer" and "SIGABRT (Abort)".
	// printf("%s\n", (char *)(lst->content));
	// printf("%s\n", (char *)(lst2->content));
	// printf("%s\n", (char *)(lst3->content));
}
