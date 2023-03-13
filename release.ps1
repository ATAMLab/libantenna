# Use this Powershell script to push releases
$version = "v1.2.0" 
$commit  = "proper sub project paths" 
Write-Output $version > version.tag
git add . && git commit -m "$commit" && git push origin && gh release create $version --title "$version" --notes "$commit"