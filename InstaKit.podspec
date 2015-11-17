Pod::Spec.new do |s|
  s.name             = "InstaKit"
  s.version          = "0.1.0"
  s.summary          = "Instagram Kit with Core Data persistence. "
  s.homepage         = "https://github.com/rinat-enikeev/InstaKit"
  s.license          = 'MIT'
  s.author           = { "Rinat Enikeev" => "rinat.enikeev@gmail.com" }
  s.source           = { :git => "https://github.com/rinat-enikeev/InstaKit.git", :tag => s.version.to_s }
  s.description      = <<-DESC
                            Instagram Kit with Core Data persistence.
                          DESC

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/**/*'
  s.resource_bundles = {
   'InstaKit' => ['Pod/Classes/**/*.xcdatamodeld']
  }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'CoreData'
  s.dependency 'RestKit'

end
