//
//  AKExpanderTests.swift
//  AudioKitTestSuite
//
//  Created by Aurelius Prochazka, revision history on GitHub.
//  Copyright © 2017 AudioKit. All rights reserved.
//

import AudioKit
import XCTest

class AKExpanderTests: AKTestCase {

    func testDefault() {
        output = AKExpander(input)
        AKTestMD5("b118304cd9c733200b0e2b6f99a41efa")
    }
}
