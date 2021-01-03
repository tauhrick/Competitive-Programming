<#list 1..5 as test_number>
  generator-small ${test_number} > $
</#list>
<#list 6..15 as test_number>
  generator ${test_number} > $
</#list>
<#list 16..20 as test_number>
  generator-sparse ${test_number} > $
</#list>
<#list 21..23 as test_number>
  generator-big ${test_number} > $
</#list>