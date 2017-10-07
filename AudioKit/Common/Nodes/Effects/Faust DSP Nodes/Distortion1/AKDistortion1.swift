//  
//  AKDistortion1.swift
//  AudioKit
//
//  Created by Max Muermann on 7/10/17.
//  Copyright © 2017 AudioKit. All rights reserved.
//

open class AKDistortion1: AKNode, AKToggleable, AKComponent, AKInput {
    public typealias AKAudioUnitType = AKDistortion1AudioUnit
    /// Four letter unique description of the node
    public static let ComponentDescription = AudioComponentDescription(effect: "dis1")

    // MARK: - Properties
    private var internalAU: AKAudioUnitType?
    private var token: AUParameterObserverToken?

    /// Ramp Time represents the speed at which parameters are allowed to change
    @objc open dynamic var rampTime: Double = AKSettings.rampTime {
        willSet {
            internalAU?.rampTime = rampTime
        }
    }

    /// Tells whether the node is processing (ie. started, playing, or active)
    @objc open dynamic var isStarted: Bool {
        return internalAU?.isPlaying() ?? false
    }

    // MARK: - Initialization

    /// Initialize this node
    ///
    /// - Parameters:
    ///   - input: Input node to process
    public init(_ input: AKNode? = nil) {
        _Self.register()

        super.init()
        AVAudioUnit._instantiate(with: _Self.ComponentDescription) { [weak self] avAudioUnit in

            self?.avAudioNode = avAudioUnit
            self?.internalAU = avAudioUnit.auAudioUnit as? AKAudioUnitType

            input?.connect(to: self!)
        }

        guard let tree = internalAU?.parameterTree else {
            AKLog("Parameter Tree Failed")
            return
        }

        token = tree.token(byAddingParameterObserver: { [weak self] _, _ in

            guard let _ = self else {
                AKLog("Unable to create strong reference to self")
                return
            } // Replace _ with strongSelf if needed
            DispatchQueue.main.async {
                // This node does not change its own values so we won't add any
                // value observing, but if you need to, this is where that goes.
            }
        })
    }

    // MARK: Parameters
    @objc open func getParameter(_ name: String)->AUParameter? {
        return internalAU?.parameterTree?[name]
    }

    @objc open func setParameter(_ name: String, to value: Float) {
        if let param = getParameter(name) {
            param.value = value
        }
    }

    // MARK: - Control

    /// Function to start, play, or activate the node, all do the same thing
    @objc open func start() {
        internalAU?.start()
    }

    /// Function to stop or bypass the node, both are equivalent
    @objc open func stop() {
        internalAU?.stop()
    }
}
